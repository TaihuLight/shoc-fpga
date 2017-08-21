#include "OpenCLEngine.h"
#include "NumberGenerator.h"
#include <sys/time.h>

#define VERBOSE true
#define PRIVATE_VECTOR_SIZE 5
#define TEMP_INIT_VALUE 1.0
#define VERIFICATION false
#define GENERATE_PTX true

const std::string currentDateTime() {
  char            fmt[64], buf[64];
  struct timeval  tv;
  struct tm       *tm;

  gettimeofday(&tv, NULL);
  tm = localtime(&tv.tv_sec);
  strftime(fmt, sizeof fmt, "%Y-%m-%d %H:%M:%S.%%06u", tm);
  snprintf(buf, sizeof buf, fmt, tv.tv_usec);
  return buf;
}

template class OpenCLEngine<float>;

template <class T>
OpenCLEngine<T>::OpenCLEngine (cl_context context, cl_device_id device,
                               int executionMode, int targetDevice,
                               struct _algorithm_type *tests) {

	this->context = context;
  this->device = device;

  this->executionMode = executionMode;
  this->targetDevice = targetDevice;

  this->tests = tests;
}

template <class T>
OpenCLEngine<T>::~OpenCLEngine () {}

template <class T>
cl_program OpenCLEngine<T>::createProgram (const char* fileName) {

	cl_int err;
  cl_program program;

  if (targetDevice == TargetDevice::GPU) {
  	// Open kernel file and check whether exists or not
    cout << "Filename is " << fileName << endl;
  	std::ifstream kernelFile (fileName, std::ios::in);
  	if (!kernelFile.is_open()) {
    	std::cerr << "Failed to open file for reading!" << fileName << std::endl;
    	exit (0);
  	}

  	std::ostringstream oss;
  	oss << kernelFile.rdbuf();

  	// Create and build a program
  	std::string srcStdStr = oss.str();
		const char *srcStr = srcStdStr.c_str();
  	program = clCreateProgramWithSource (this->context, 1, (const char **)&srcStr,
                                       NULL, &err);
  	CL_CHECK_ERROR (err);
  } else if (targetDevice == TargetDevice::FPGA) {
		string binary_file = aocl_utils::getBoardBinaryFile (fileName, this->device);
    program = aocl_utils::createProgramFromBinary (this->context, binary_file.c_str(), &(this->device), 1);
	}
	cout << "Before cl build program!" << endl;
  err = clBuildProgram (program, 0, NULL, opts, NULL, NULL);
  cout << "Error is " << err << endl;
  if (err != 0) {
    char log[5000];
    size_t retsize = 0;
    err = clGetProgramBuildInfo (program, this->device, CL_PROGRAM_BUILD_LOG,
                                5000*sizeof(char), log, &retsize);
    //CL_CHECK_ERROR (err);

    cout << "Build Error!" << endl;
    cout << "retSize: " << retsize << endl;
    cout << "Log: " << log << endl;
    exit (0);
  }
  CL_CHECK_ERROR (err);

  return program;

}

template <class T>
bool OpenCLEngine<T>::createMemObjects (cl_command_queue queue, cl_mem *memObjects,
                                     int singleElementSize, const long long memSize,
                                     T *data) {

	cl_int err;


  *memObjects = clCreateBuffer (this->context, CL_MEM_READ_WRITE,
                                memSize * singleElementSize, NULL, &err);
  CL_CHECK_ERROR (err);

  if (*memObjects == NULL) {
    std::cerr << "Error creating memory objects. " << std::endl;
    return false;
  }

  // Enqueue data buffer
  Event evWriteData ("write-data");
  err = clEnqueueWriteBuffer (queue, *memObjects, CL_TRUE, 0, memSize * singleElementSize,
                              data, 0, NULL, &evWriteData.CLEvent());
  CL_CHECK_ERROR (err);
  err = clWaitForEvents (1, &evWriteData.CLEvent());
  CL_CHECK_ERROR (err);

  return true;
}

template <class T>
bool OpenCLEngine<T>::refillMemObject (cl_command_queue queue,
                      cl_mem* memObject, int singleElementSize,
                      const long long memSize, T *data) {

  cl_int err;

  Event evWriteData ("write-data");
  err = clEnqueueWriteBuffer (queue, *memObject, true, 0,
                              memSize * singleElementSize, data,
                              0, NULL, &evWriteData.CLEvent());
  CL_CHECK_ERROR (err);
  err = clWaitForEvents (1, &evWriteData.CLEvent());
  CL_CHECK_ERROR (err);

  return true;
}

template <class T>
void OpenCLEngine<T>::generateCLs () {

	int aIdx = 0;
  while ((tests != 0) && (tests[aIdx].name != 0)) {
    ostringstream oss;
    struct _cl_info test_cl_info;
    struct _algorithm_type temp = tests[aIdx];
		generateSingleCLCode (oss, temp, test_cl_info);
    aIdx++;
  }

}

template <class T>
void OpenCLEngine<T>::generateCLsMetas () {

	int aIdx = 0;
  while ((tests != 0) && (tests[aIdx].name != 0)) {
   	struct _cl_info test_cl_info;
    struct _algorithm_type temp = tests[aIdx];
		generateSingleCLMeta (temp, test_cl_info);
    cl_metas.push_back (test_cl_info);
    aIdx++;
  }

}

template <class T>
void OpenCLEngine<T>::generateSingleCLCode (ostringstream &oss, struct _algorithm_type &test, struct _cl_info &info) {

	if (VERBOSE) cout << "[VERBOSE] Generate Single CL Code for " << test.name << endl;

  if (test.loopCarriedDataDependency == false) {
  	ofstream codeDump;
  	string dumpFileName = gpu_built_kernels_folder + "/" + test.name + ".cl";
  	codeDump.open (dumpFileName.c_str());
		if (!codeDump.is_open()) {
      cout << "[ERROR] Dump File cannot be created or opened!" << endl;
    }

    //  	if (strcmp (test.varType, "double")) {
		//	oss << "#pragma OPENCL EXTENSION cl_khr_fp64: enable" << endl;
    //	oss << endl;
  	//}

		oss << "__kernel void " << test.name << "(__global " << test.varType << " *data, __global " << test.varType << " *rands, int index, int rand_max){" << endl;
    string declFormula = preparedVarDeclFormulaNonArray ((char *)test.varDeclFormula, PRIVATE_VECTOR_SIZE, false);
    insertTab (oss, 1); oss << declFormula << ";" << endl;
    if (!test.doLocalMemory) {
			insertTab (oss ,1); oss << "int gid = get_global_id(0);" << endl;
    } else {
			string localMemoryInit = preparedLocalMemoryInitialization (test.loopsDepth[0], test.varType, (char **)&(test.formula));
      oss << localMemoryInit << endl;
    }
    oss << endl;
    insertTab (oss, 1); oss << test.varInitFormula << ";" << endl;
		if (VERBOSE) cout << "[VERBOSE] Init Formula been inserted successfully!" << endl;

    if (test.doManualUnroll == true ) {
			NumberGenerator numberGenerator (test.loopsDepth[0]);
			if (VERBOSE) cout << "[VERBOSE] Manually Unrolling is True!" << endl;
	  	for (int i = 1; i < test.loopsDepth[0]; i++) {
        string origFormula;
        if (test.randomAccessType == RandomAccessType::SEQUENTIAL)
					origFormula = prepareOriginalFormula ((char *)test.formula, numberGenerator.getNextSequential()+1, (char *) test.variable);
        else if (test.randomAccessType == RandomAccessType::RANDOM)
          origFormula = prepareOriginalFormula ((char *)test.formula, numberGenerator.getNextRandom()+1, (char *) test.variable);
	      insertTab (oss, 1); oss << origFormula << ";" << endl;
	  	}
    } else {
      if (VERBOSE) cout << "[VERBOSE] Manually Unrolling is False!" << endl;
      if (test.randomAccessType != RandomAccessType::SEQUENTIAL)
        cout << "[WARNING] random access type cannot be generated for automatically unrolled kernels!" << endl
             << "\tPlease re-design your \"test.h\" file!" << endl;
      if (test.unrollFactor != 0) {
      	insertTab (oss, 1); oss << "#pragma unroll " << test.unrollFactor << endl;
      }
      insertTab (oss, 1); oss << "for (int i = 0; i < " << test.loopsDepth[0] << "; i++){" << endl;
    	string origFormula = prepareOriginalFormula ((char *)test.formula, 0, (char *) test.variable);
      insertTab (oss, 2); oss << origFormula << ";" << endl;
      insertTab (oss, 1); oss << "}" << endl;
    }

    int pos = -1;
	  char returnBuf[32];

		string returnOpCode = prepareReturnOpCode (test.vectorSize, test.returnFormula);

		//string returnOpCode = string (test.returnFormula);
    //if ((pos = returnOpCode.find("$")) != (-1) )
    //returnOpCode.replace (pos, 1, string("0"));
      //returnOpCode.replace (pos, 1, string("index"));
		if (VERBOSE) cout << "[VERBOSE] Return Op Code been prepared!" << endl;

    insertTab (oss, 1); oss << returnOpCode << ";" << endl;

  	oss << endl;
  	oss << "}" << endl;
    codeDump << oss.str();
    codeDump.close ();

    if (VERBOSE) cout << "[VERBOSE] CL Code for " << test.name << " been created successfully!" << endl;

  }

  else if (test.loopCarriedDataDependency == true) {

		cout << "in lcdd" << endl;

		ofstream codeDump;
    string dumpFileName = gpu_built_kernels_folder + "/" + test.name + ".cl";
		codeDump.open (dumpFileName.c_str());

    oss << "__kernel void " << test.name << "(global " << test.varType << " *data, __global " << test.varType << " *rands, int index, int rand_max){" << endl << endl;

		string declFormula = preparedVarDeclFormulaNonArray ((char *)test.varDeclFormula, test.loopsDepth[0], true);

    insertTab (oss, 1); oss << declFormula << ";" << endl;
    if (!test.doLocalMemory) {
      insertTab (oss, 1); oss << "int depth = " << test.loopsDepth[0] << ";" << endl;
    	insertTab (oss, 1); oss << "int gid = get_global_id(0);" << endl;
    } else {
      string localMemoryInit = preparedLocalMemoryInitialization (test.loopsDepth[0], test.varType, (char **)&(test.variable));
      oss << localMemoryInit << endl;
    }

    oss << endl;
    insertTab (oss, 1); oss << test.varInitFormula << ";" << endl;
		oss << endl;

		if (test.doManualUnroll == true) {
    	for (int i = 1; i < test.loopsDepth[0]; i++) {
      	string origFormula = prepareOriginalFormula ((char *)test.formula, i, (char *)test.variable);
				insertTab (oss, 1); oss << origFormula << ";" << endl;
    	}
    } else {
      insertTab (oss, 1); oss << "for (int j = 0; j < " << test.loopsLengths[0] << "; j++){" << endl;
      insertTab (oss, 2); oss << "for (int i = 0; i < " << test.loopsDepth[0] << "; i++){" << endl;
      string origFormula = prepareOriginalFormula ((char *) test.formula, 0, (char *) test.variable);
      insertTab (oss, 3); oss << origFormula << ";" << endl;
      insertTab (oss, 2); oss << "}" << endl;
			insertTab (oss, 2); oss << "tempbefore = tempnow * rands[j%depth];" << endl;
      insertTab (oss, 1); oss << "}" << endl;
    }

    int pos = -1;
    char returnBuf[32];
    string returnOpCode = string (test.returnFormula);
    if ((pos = returnOpCode.find("$")) != (-1))
      returnOpCode.replace (pos, 1, string("0"));

    insertTab (oss, 1); oss << returnOpCode << ";" << endl;

    oss << endl;
    oss << "}" << endl;
    codeDump << oss.str();
    codeDump.close();

  }
}

template <class T>
void OpenCLEngine<T>::generateSingleCLMeta (_algorithm_type &test, _cl_info &info) {

  memcpy (info.name, (char *)test.name, strlen((char *)test.name));
  if (targetDevice == TargetDevice::GPU)
  	memcpy (info.kernel_location, (char *)(string(gpu_built_kernels_folder + "/" + test.name + ".cl").c_str()),
            strlen((char *)(string(gpu_built_kernels_folder + "/" + test.name + ".cl").c_str())));
  else
    memcpy (info.kernel_location, (char *)(string(fpga_built_kernels_folder + "/" + test.name).c_str()),
            strlen((char *)(string(fpga_built_kernels_folder + "/" + test.name).c_str())));
  info.num_workitems = test.loopsLengths[0];
	info.flops = test.flopCount;

}

// Generate Single-Thread CPU code based on benchmark type struct
//template <class T>
//void OpenCLEngine<T>::generateAlgorithms ( ) {

//  int aIdx = 0;
//  while ((tests != 0) && (tests[aIdx].name != 0)) {
//  	ostringstream oss;
//    struct _algorithm_type temp = tests[aIdx];
//		generateSingleAlgorithm (oss, temp);
//    aIdx++;
//  }
//}

template <class T>
void OpenCLEngine<T>::insertTab (ostringstream &oss, int numTabs) {

	for (int i = 0; i < numTabs; i++) {
    oss << "\t";
  }

}

template <class T>
void OpenCLEngine<T>::print_benchmark () {
  int aIdx = 0;
  while ((tests != 0) && (tests[aIdx].name != 0)) {
    struct _algorithm_type temp = tests[aIdx];

    cout << "[TEST] ";
    cout << "{name:" << temp.name << "},";
    cout << "{numLoops:" << temp.numLoops << "},";
    cout << "{loopsLengths:";
    for (int i = 0; i < temp.numLoops; i++) {
      cout << temp.loopsLengths[i] << ",";
    }
    cout << "},";
    cout << "{loopsDepths:";
    for (int i = 0; i < temp.numLoops; i++) {
      cout << temp.loopsDepth[i] << ",";
    }
    cout << "},";
    cout << "{LoopCarried:" << temp.loopCarriedDataDependency << "},";
    cout << "{loopCarriedDepths:";
    for (int i = 0; i < temp.numLoops; i++) {
      cout << temp.loopCarriedDDLengths[i] << ",";
    }
    cout << "},";
    cout << "{varType:" << temp.varType << "}";
    cout << endl;
    aIdx++;
  }
}

template <class T>
void OpenCLEngine<T>::validate_benchmark () {

	int aIdx = 0;

  while ((tests != 0) && (tests[aIdx].name != 0)) {
    struct _algorithm_type temp = tests[aIdx];

    if (temp.numLoops != 1) {
      cout << "WARNING: Number of loops cannot exceed 1 in current version!\n";
    	exit (0);
    }

    if (temp.loopsLengths.size() != temp.numLoops) {
      cout << "ERROR: Size of loops lengths vector should be similar to number of loops!\n";
      exit (0);
    }

    if (temp.loopsDepth.size() != temp.numLoops) {
      cout << "ERROR: Size of loops depths should be similar to number of loops!\n";
      exit (0);
    }

		if (temp.loopCarriedDDLengths.size() != temp.numLoops) {
      cout << "ERROR: Size of loop carried data depndency lengths should be similar to number of loops!\n";
      exit (0);
    }
    aIdx++;
  }

}

template <class T>
void OpenCLEngine<T>::executionCL (cl_device_id id,
                cl_context ctx,
                cl_command_queue queue,
                ResultDatabase &resultDB,
                OptionParser &op,
                char* precision,
                AlgorithmFactory& algorithmFactory) {

	int verbose = true;
	int npasses = 5;
	int err;
  char sizeStr[128];

	T *hostMem_GIn;
  T *hostMem_GOut;
	T *verification_GOut;
  cl_mem mem_GIn;
  cl_mem mem_GOut;

	if (verbose) cout << "start execution!" << endl;

  int aIdx = 0;

  while (true) {
    Algorithm* algorithm = algorithmFactory.nextAlgorithm ();
    if (algorithm == NULL) break;

    if (verbose) cout << "current algorithm name for execution is: " << algorithm->getKernelName () << endl;

    cl_program program;
    cl_kernel kernel;

    long long GInSize = algorithm->getGInSize ();
    long long GOutSize = algorithm->getGOutSize ();

		hostMem_GIn = new T[GInSize];
    hostMem_GOut = new T[GOutSize];
    verification_GOut = new T[GOutSize];

    program = createProgram ((algorithm->getKernelLocation ()).c_str());
    if (program == NULL)
      exit (0);
    if (verbose) std::cout << "Program Created Successfully!" << endl;

    kernel = clCreateKernel (program, (algorithm->getKernelName ()).c_str(), &err);
    CL_CHECK_ERROR (err);
    if (verbose) cout << "Kernel Created Successfully!" << endl;

		if (GENERATE_PTX) {
      size_t bin_sz;
      err = clGetProgramInfo (program, CL_PROGRAM_BINARY_SIZES,
                              sizeof(size_t), &bin_sz, NULL);
      // Read binary (PTX file) to memory buffer
      unsigned char* bin = (unsigned char*) malloc (bin_sz);
      err = clGetProgramInfo (program, CL_PROGRAM_BINARIES,
                              sizeof(unsigned char *), &bin, NULL);

      FILE* fp = fopen ("binary.ptx", "wb");
      fwrite (bin, sizeof(char), bin_sz, fp);
      fclose (fp);
      free (bin);
    }

		createMemObjects (queue, &mem_GIn, (int) sizeof (T), GInSize, hostMem_GIn);
    CL_CHECK_ERROR (err);

    createMemObjects (queue, &mem_GOut, (int) sizeof (T), GOutSize, hostMem_GOut);
    CL_CHECK_ERROR (err);

    /*
    err = clSetKernelArg (kernel, 0, sizeof (cl_mem), (void *)&mem_GIn);
    CL_CHECK_ERROR (err);

    err = clSetKernelArg (kernel, 1, sizeof (cl_mem), (void *)&mem_GOut);
    CL_CHECK_ERROR (err);

    // It's time to fill values M, N, and P in version 2 of generator
    if (algorithm->getIsV2 ()) {
      int *M = new int;
			int *N = new int;
      int *P = new int;
      M[0] = algorithm->getM(); N[0] = algorithm->getN(); P[0] = algorithm->getP();
      err = clSetKernelArg (kernel, 2, sizeof (int), (void *)M);
      CL_CHECK_ERROR (err);

      err = clSetKernelArg (kernel, 3, sizeof (int), (void *)N);
      CL_CHECK_ERROR (err);

      err = clSetKernelArg (kernel, 4, sizeof (int), (void *)P);
      CL_CHECK_ERROR (err);
    }
		*/

    // Set up input memory for data, first half = second half
    for (int j = 0; j < GInSize; j++)
      hostMem_GIn[j] = (T)(drand48()*5.0);

    int* wsBegin;
    while ((wsBegin = algorithm->nextLocalWorkSize ()) != NULL) {

      char lwsString[10] = {'\0'};
      for (int pas = 0; pas < npasses; ++pas) {

        refillMemObject (queue, &mem_GIn, (int) sizeof (T), GInSize, hostMem_GIn);
        refillMemObject (queue, &mem_GOut, (int) sizeof (T), GOutSize, hostMem_GOut);

        err = clSetKernelArg (kernel, 0, sizeof (cl_mem), (void *)&mem_GIn);
        CL_CHECK_ERROR (err);

        err = clSetKernelArg (kernel, 1, sizeof (cl_mem), (void *)&mem_GOut);
        CL_CHECK_ERROR (err);

        // It's time to fill values M, N, and P in version 2 of generator
        if (algorithm->getIsV2 ()) {
          int *M = new int;
          int *N = new int;
          int *P = new int;
          M[0] = algorithm->getM(); N[0] = algorithm->getN(); P[0] = algorithm->getP();
          err = clSetKernelArg (kernel, 2, sizeof (int), (void *)M);
          CL_CHECK_ERROR (err);

          err = clSetKernelArg (kernel, 3, sizeof (int), (void *)N);
          CL_CHECK_ERROR (err);

          err = clSetKernelArg (kernel, 4, sizeof (int), (void *)P);
          CL_CHECK_ERROR (err);
        }


        size_t* globalWorkSize = new size_t[algorithm->getWorkDim()];
        size_t* localMemSize = new size_t[algorithm->getWorkDim()];

        for (int i = 0; i < algorithm->getWorkDim(); i++) {
          globalWorkSize[i] = (size_t) algorithm->getGlobalWorkSize()[i];
          localMemSize[i] = (size_t) wsBegin[i];
        }
        //size_t localWorkSize[1];
        //globalWorkSize[0] = algorithm->getGlobalWorkSize ();
        //localWorkSize[0] = wsBegin;
        //if (verbose)
          //cout << "--Executing kernel with global work size " << globalWorkSize[0] << endl
          //     << "--and local work size " << localWorkSize[0] << endl
          //     << "--and total number of floating point operations as " << algorithm->getTotalNumFlops ()
          //     << endl;
        Event evKernel (algorithm->getKernelName ());
        err = clEnqueueNDRangeKernel (queue, kernel, algorithm->getWorkDim(),
                                      NULL,
                                      globalWorkSize,
                                      localMemSize,
                                      0, NULL, &evKernel.CLEvent());
        CL_CHECK_ERROR (err);
        err = clWaitForEvents (1, &evKernel.CLEvent());
        //cout << "err is " << err << endl;
        //CL_CHECK_ERROR (err);

        evKernel.FillTimingInfo ();

        //double TNF = algorithm->getTotalNumFlops ();
        //double time = evKernel.SubmitEndRuntime ();
        //cout << "TNF: " << TNF << ", Time: " << time << endl;
        double gflop = (double)algorithm->getTotalNumFlops () / (double)(evKernel.StartEndRuntime());
				//sprintf (sizeStr, "Size: %07d", algorithm->getGlobalWorkSize ());
        //sprintf (lwsString, "%d", wsBegin);
        resultDB.AddResult (string(algorithm->getKernelName ()) + string("-lws") + string (lwsString) + string ("-") + string(precision), sizeStr, "GFLOPS", gflop);

        CL_CHECK_ERROR (err);
      }
    }

    err = clReleaseKernel (kernel);
    CL_CHECK_ERROR (err);
    err = clReleaseProgram (program);
    CL_CHECK_ERROR (err);
    err = clReleaseMemObject (mem_GIn);
    CL_CHECK_ERROR (err);
    err = clReleaseMemObject (mem_GOut);
    CL_CHECK_ERROR (err);

    delete[] hostMem_GIn;
    delete[] hostMem_GOut;
    delete[] verification_GOut;
	}

}

template <class T>
string OpenCLEngine<T>::preparedVarDeclFormula (char *varDeclFormula, int depth) {

  string declFormula = string (varDeclFormula);
  char depthBuf[32];
  sprintf (depthBuf, "%d", depth);
  string depthSize = string (depthBuf);
	int pos = -1;
  while ((pos = declFormula.find ("$")) != -1)
    declFormula.replace (pos, 1, depthSize);

	if (VERBOSE)
    cout << "Var Decl Formula been prepared!" << endl;

  return declFormula;
}

template <class T>
string OpenCLEngine<T>::preparedVarDeclFormulaNonArray (char *varDeclFormula, int depth, bool lcdd) {

	string completeDeclFormula;

  if (lcdd == false) {

		// Check whether we have $ sign in the varDeclFormula
  	string declFormula = string (varDeclFormula);
  	int pos = -1;
  	if ((pos = declFormula.find ("$")) == -1)
    	depth = 1;

  	for (int i = 0; i < depth; i++) {
    	string declFormula = string (varDeclFormula);
    	char depthBuf[32];
    	sprintf (depthBuf, "%d", i);
    	string depthSize = string (depthBuf);
    	int pos = -1;
    	while ((pos = declFormula.find ("$")) != -1)
      	declFormula.replace (pos, 1, depthSize);

			if (i != (depth -1))
    		completeDeclFormula += (declFormula + ";\n");
    	else
				completeDeclFormula += (declFormula);

  	}
  } else {

    // Check whether we have $ sing in the varDeclFormula
    string declFormula = string (varDeclFormula);
    int pos = -1;
    //if ((pos = declFormula.find ("$")) == -1)
    //  exit (0);

    char depthBuf[32];
    sprintf (depthBuf, "%d", depth);
    string depthSize = string (depthBuf);
    pos = -1;
    while ((pos = declFormula.find("$")) != -1)
      declFormula.replace (pos, 1, depthSize);

   	completeDeclFormula = declFormula;

  }

  if (VERBOSE) cout << "[VERBOSE] Var Decl Formula been prepared!" << endl;

  return completeDeclFormula;
}

template <class T>
string OpenCLEngine<T>::prepareOriginalFormula (char *formula, int index, char *variable) {

	int pos = -1;

	string formulaStr = string (formula);
  char indexBuf[32];
  char indexBuf2[32];
  char indexBuf3[32];
  sprintf (indexBuf, "%d", index%PRIVATE_VECTOR_SIZE);
  sprintf (indexBuf2, "%d", (index-1)%PRIVATE_VECTOR_SIZE);
  if (index != 0)
  	sprintf (indexBuf3, "%d", (index-1));
  else
    sprintf (indexBuf3, "%c", 'i');

  string indexStr = string (indexBuf);
  string indexStr2 = string (indexBuf2);

  while ((pos = formulaStr.find ("$")) != (-1))
		formulaStr.replace (pos, 1, indexStr);

	pos = -1;
  formulaStr = string (formulaStr);
  while ((pos = formulaStr.find ("!")) != (-1))
    formulaStr.replace (pos, 1, indexBuf3);

  pos = -1;
  formulaStr = string (formulaStr);
  while ((pos = formulaStr.find ("#")) != (-1))
    formulaStr.replace (pos, 1, indexStr2);

  pos = -1;
  formulaStr = string (formulaStr);
  while ((pos = formulaStr.find("@")) != (-1))
    formulaStr.replace (pos, 1, string (variable));

	if (VERBOSE)
		cout << "[VERBOSE] Original Formula been prepared!";

  return formulaStr;

}

template <class T>
string OpenCLEngine<T>::preparedLocalMemoryInitialization (int depth, string dataType, char** origFormula) {

  // Preparing the intialization of local memory
	string return_statement;
	return_statement += (string("\t") + string("__local ")+ dataType + string(" localRands[") + to_string(depth) + string("];\n"));
  return_statement += (string("\t") + string("int depth = ") + to_string(depth) + string(";\n\n"));
  return_statement += (string("\t") + string("int gid = get_global_id(0);\n"));
  return_statement += (string("\t") + string("int lid = get_local_id(0);\n"));
  return_statement += (string("\t") + string("int localWorkSize = get_local_size(0);\n"));
  return_statement += (string("\t") + string("int workItemCopyPortion = depth / localWorkSize;\n\n"));
  return_statement += (string("\t") + string("event_t event = async_work_group_copy (localRands, &(rands[lid * workItemCopyPortion]), (depth - lid*workItemCopyPortion < workItemCopyPortion) ? (depth - lid*workItemCopyPortion) : workItemCopyPortion, 0);\n"));
	return_statement += (string("\t") + string("wait_group_events(1, &event);\n"));
	if (VERBOSE)
    cout << "[VERBOSE] return statement been prepared successfully!" << endl;
  // replace rands in original formula with localRands, if it does exists
	int pos = -1;
  string origFormulaStr = string(*origFormula);
  while ((pos = origFormulaStr.find ("rands")) != -1)
    origFormulaStr.replace (pos, 5, "localRands");

  int length = origFormulaStr.size();
  char* newOrigFormula = (char *) malloc (50 * sizeof(char));
  memcpy (newOrigFormula, origFormulaStr.c_str(), length);

  newOrigFormula[length] = '\0';
	*origFormula = newOrigFormula;
	if (VERBOSE)
    cout << "[VERBOSE] rands been replaced with localRands" << endl;


	return return_statement;

}

template <class T>
string OpenCLEngine<T>::prepareReturnOpCode (int streamSize, string returnOpCode) {

  string finalReturnOpCode = (returnOpCode + " = ");

  for (int i = 0; i < streamSize; i++){
    if (i == 10)
      finalReturnOpCode += (string("temp.s") + string("A"));
  	else if (i == 11)
      finalReturnOpCode += (string("temp.s") + string("B"));
    else if (i == 12)
			finalReturnOpCode += (string("temp.s") + string("C"));
    else if (i == 13)
      finalReturnOpCode += (string("temp.s") + string("D"));
    else if (i == 14)
      finalReturnOpCode += (string("temp.s") + string("E"));
    else if (i == 15)
      finalReturnOpCode += (string("temp.s") + string("F"));
		else
			finalReturnOpCode += (string("temp.s") + to_string(i));

    if (i != streamSize-1)
      finalReturnOpCode += string(" + ");
  }

  return finalReturnOpCode;
}

