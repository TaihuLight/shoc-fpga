#ifndef TestS2VfloatD256Form1MUnrol1U0LM1RAND_H_
#define TestS2VfloatD256Form1MUnrol1U0LM1RAND_H_

__global__ void TestS2VfloatD256Form1MUnrol1U0LM1RAND( float *data, float *rands, int index, int rand_max){
	float2 temp;
	__shared__ float localRands[256];
	int depth = 256;

	int gid = blockIdx.x * blockDim.x + threadIdx.x;
	int lid = threadIdx.x;
	int blockSize = blockDim.x;
	for(int i = lid; i < depth; i += blockSize) {
		localRands[i] = rands[i];
	}
	__syncthreads();



	temp.x = data[gid];
	temp.y = data[gid];;
	temp.x = (float) localRands[29] * temp.x + localRands[29];
		temp.y = (float) localRands[29] * temp.y + localRands[29];;
	temp.x = (float) localRands[56] * temp.x + localRands[56];
		temp.y = (float) localRands[56] * temp.y + localRands[56];;
	temp.x = (float) localRands[102] * temp.x + localRands[102];
		temp.y = (float) localRands[102] * temp.y + localRands[102];;
	temp.x = (float) localRands[101] * temp.x + localRands[101];
		temp.y = (float) localRands[101] * temp.y + localRands[101];;
	temp.x = (float) localRands[184] * temp.x + localRands[184];
		temp.y = (float) localRands[184] * temp.y + localRands[184];;
	temp.x = (float) localRands[228] * temp.x + localRands[228];
		temp.y = (float) localRands[228] * temp.y + localRands[228];;
	temp.x = (float) localRands[42] * temp.x + localRands[42];
		temp.y = (float) localRands[42] * temp.y + localRands[42];;
	temp.x = (float) localRands[62] * temp.x + localRands[62];
		temp.y = (float) localRands[62] * temp.y + localRands[62];;
	temp.x = (float) localRands[94] * temp.x + localRands[94];
		temp.y = (float) localRands[94] * temp.y + localRands[94];;
	temp.x = (float) localRands[218] * temp.x + localRands[218];
		temp.y = (float) localRands[218] * temp.y + localRands[218];;
	temp.x = (float) localRands[133] * temp.x + localRands[133];
		temp.y = (float) localRands[133] * temp.y + localRands[133];;
	temp.x = (float) localRands[230] * temp.x + localRands[230];
		temp.y = (float) localRands[230] * temp.y + localRands[230];;
	temp.x = (float) localRands[152] * temp.x + localRands[152];
		temp.y = (float) localRands[152] * temp.y + localRands[152];;
	temp.x = (float) localRands[243] * temp.x + localRands[243];
		temp.y = (float) localRands[243] * temp.y + localRands[243];;
	temp.x = (float) localRands[244] * temp.x + localRands[244];
		temp.y = (float) localRands[244] * temp.y + localRands[244];;
	temp.x = (float) localRands[55] * temp.x + localRands[55];
		temp.y = (float) localRands[55] * temp.y + localRands[55];;
	temp.x = (float) localRands[77] * temp.x + localRands[77];
		temp.y = (float) localRands[77] * temp.y + localRands[77];;
	temp.x = (float) localRands[5] * temp.x + localRands[5];
		temp.y = (float) localRands[5] * temp.y + localRands[5];;
	temp.x = (float) localRands[246] * temp.x + localRands[246];
		temp.y = (float) localRands[246] * temp.y + localRands[246];;
	temp.x = (float) localRands[157] * temp.x + localRands[157];
		temp.y = (float) localRands[157] * temp.y + localRands[157];;
	temp.x = (float) localRands[21] * temp.x + localRands[21];
		temp.y = (float) localRands[21] * temp.y + localRands[21];;
	temp.x = (float) localRands[4] * temp.x + localRands[4];
		temp.y = (float) localRands[4] * temp.y + localRands[4];;
	temp.x = (float) localRands[117] * temp.x + localRands[117];
		temp.y = (float) localRands[117] * temp.y + localRands[117];;
	temp.x = (float) localRands[160] * temp.x + localRands[160];
		temp.y = (float) localRands[160] * temp.y + localRands[160];;
	temp.x = (float) localRands[69] * temp.x + localRands[69];
		temp.y = (float) localRands[69] * temp.y + localRands[69];;
	temp.x = (float) localRands[201] * temp.x + localRands[201];
		temp.y = (float) localRands[201] * temp.y + localRands[201];;
	temp.x = (float) localRands[142] * temp.x + localRands[142];
		temp.y = (float) localRands[142] * temp.y + localRands[142];;
	temp.x = (float) localRands[96] * temp.x + localRands[96];
		temp.y = (float) localRands[96] * temp.y + localRands[96];;
	temp.x = (float) localRands[121] * temp.x + localRands[121];
		temp.y = (float) localRands[121] * temp.y + localRands[121];;
	temp.x = (float) localRands[39] * temp.x + localRands[39];
		temp.y = (float) localRands[39] * temp.y + localRands[39];;
	temp.x = (float) localRands[151] * temp.x + localRands[151];
		temp.y = (float) localRands[151] * temp.y + localRands[151];;
	temp.x = (float) localRands[95] * temp.x + localRands[95];
		temp.y = (float) localRands[95] * temp.y + localRands[95];;
	temp.x = (float) localRands[252] * temp.x + localRands[252];
		temp.y = (float) localRands[252] * temp.y + localRands[252];;
	temp.x = (float) localRands[23] * temp.x + localRands[23];
		temp.y = (float) localRands[23] * temp.y + localRands[23];;
	temp.x = (float) localRands[217] * temp.x + localRands[217];
		temp.y = (float) localRands[217] * temp.y + localRands[217];;
	temp.x = (float) localRands[85] * temp.x + localRands[85];
		temp.y = (float) localRands[85] * temp.y + localRands[85];;
	temp.x = (float) localRands[1] * temp.x + localRands[1];
		temp.y = (float) localRands[1] * temp.y + localRands[1];;
	temp.x = (float) localRands[219] * temp.x + localRands[219];
		temp.y = (float) localRands[219] * temp.y + localRands[219];;
	temp.x = (float) localRands[30] * temp.x + localRands[30];
		temp.y = (float) localRands[30] * temp.y + localRands[30];;
	temp.x = (float) localRands[153] * temp.x + localRands[153];
		temp.y = (float) localRands[153] * temp.y + localRands[153];;
	temp.x = (float) localRands[206] * temp.x + localRands[206];
		temp.y = (float) localRands[206] * temp.y + localRands[206];;
	temp.x = (float) localRands[18] * temp.x + localRands[18];
		temp.y = (float) localRands[18] * temp.y + localRands[18];;
	temp.x = (float) localRands[209] * temp.x + localRands[209];
		temp.y = (float) localRands[209] * temp.y + localRands[209];;
	temp.x = (float) localRands[28] * temp.x + localRands[28];
		temp.y = (float) localRands[28] * temp.y + localRands[28];;
	temp.x = (float) localRands[199] * temp.x + localRands[199];
		temp.y = (float) localRands[199] * temp.y + localRands[199];;
	temp.x = (float) localRands[185] * temp.x + localRands[185];
		temp.y = (float) localRands[185] * temp.y + localRands[185];;
	temp.x = (float) localRands[45] * temp.x + localRands[45];
		temp.y = (float) localRands[45] * temp.y + localRands[45];;
	temp.x = (float) localRands[203] * temp.x + localRands[203];
		temp.y = (float) localRands[203] * temp.y + localRands[203];;
	temp.x = (float) localRands[46] * temp.x + localRands[46];
		temp.y = (float) localRands[46] * temp.y + localRands[46];;
	temp.x = (float) localRands[205] * temp.x + localRands[205];
		temp.y = (float) localRands[205] * temp.y + localRands[205];;
	temp.x = (float) localRands[16] * temp.x + localRands[16];
		temp.y = (float) localRands[16] * temp.y + localRands[16];;
	temp.x = (float) localRands[247] * temp.x + localRands[247];
		temp.y = (float) localRands[247] * temp.y + localRands[247];;
	temp.x = (float) localRands[92] * temp.x + localRands[92];
		temp.y = (float) localRands[92] * temp.y + localRands[92];;
	temp.x = (float) localRands[112] * temp.x + localRands[112];
		temp.y = (float) localRands[112] * temp.y + localRands[112];;
	temp.x = (float) localRands[131] * temp.x + localRands[131];
		temp.y = (float) localRands[131] * temp.y + localRands[131];;
	temp.x = (float) localRands[254] * temp.x + localRands[254];
		temp.y = (float) localRands[254] * temp.y + localRands[254];;
	temp.x = (float) localRands[7] * temp.x + localRands[7];
		temp.y = (float) localRands[7] * temp.y + localRands[7];;
	temp.x = (float) localRands[226] * temp.x + localRands[226];
		temp.y = (float) localRands[226] * temp.y + localRands[226];;
	temp.x = (float) localRands[249] * temp.x + localRands[249];
		temp.y = (float) localRands[249] * temp.y + localRands[249];;
	temp.x = (float) localRands[204] * temp.x + localRands[204];
		temp.y = (float) localRands[204] * temp.y + localRands[204];;
	temp.x = (float) localRands[43] * temp.x + localRands[43];
		temp.y = (float) localRands[43] * temp.y + localRands[43];;
	temp.x = (float) localRands[79] * temp.x + localRands[79];
		temp.y = (float) localRands[79] * temp.y + localRands[79];;
	temp.x = (float) localRands[3] * temp.x + localRands[3];
		temp.y = (float) localRands[3] * temp.y + localRands[3];;
	temp.x = (float) localRands[44] * temp.x + localRands[44];
		temp.y = (float) localRands[44] * temp.y + localRands[44];;
	temp.x = (float) localRands[33] * temp.x + localRands[33];
		temp.y = (float) localRands[33] * temp.y + localRands[33];;
	temp.x = (float) localRands[197] * temp.x + localRands[197];
		temp.y = (float) localRands[197] * temp.y + localRands[197];;
	temp.x = (float) localRands[248] * temp.x + localRands[248];
		temp.y = (float) localRands[248] * temp.y + localRands[248];;
	temp.x = (float) localRands[51] * temp.x + localRands[51];
		temp.y = (float) localRands[51] * temp.y + localRands[51];;
	temp.x = (float) localRands[150] * temp.x + localRands[150];
		temp.y = (float) localRands[150] * temp.y + localRands[150];;
	temp.x = (float) localRands[20] * temp.x + localRands[20];
		temp.y = (float) localRands[20] * temp.y + localRands[20];;
	temp.x = (float) localRands[75] * temp.x + localRands[75];
		temp.y = (float) localRands[75] * temp.y + localRands[75];;
	temp.x = (float) localRands[93] * temp.x + localRands[93];
		temp.y = (float) localRands[93] * temp.y + localRands[93];;
	temp.x = (float) localRands[120] * temp.x + localRands[120];
		temp.y = (float) localRands[120] * temp.y + localRands[120];;
	temp.x = (float) localRands[40] * temp.x + localRands[40];
		temp.y = (float) localRands[40] * temp.y + localRands[40];;
	temp.x = (float) localRands[251] * temp.x + localRands[251];
		temp.y = (float) localRands[251] * temp.y + localRands[251];;
	temp.x = (float) localRands[242] * temp.x + localRands[242];
		temp.y = (float) localRands[242] * temp.y + localRands[242];;
	temp.x = (float) localRands[161] * temp.x + localRands[161];
		temp.y = (float) localRands[161] * temp.y + localRands[161];;
	temp.x = (float) localRands[169] * temp.x + localRands[169];
		temp.y = (float) localRands[169] * temp.y + localRands[169];;
	temp.x = (float) localRands[99] * temp.x + localRands[99];
		temp.y = (float) localRands[99] * temp.y + localRands[99];;
	temp.x = (float) localRands[36] * temp.x + localRands[36];
		temp.y = (float) localRands[36] * temp.y + localRands[36];;
	temp.x = (float) localRands[167] * temp.x + localRands[167];
		temp.y = (float) localRands[167] * temp.y + localRands[167];;
	temp.x = (float) localRands[106] * temp.x + localRands[106];
		temp.y = (float) localRands[106] * temp.y + localRands[106];;
	temp.x = (float) localRands[6] * temp.x + localRands[6];
		temp.y = (float) localRands[6] * temp.y + localRands[6];;
	temp.x = (float) localRands[154] * temp.x + localRands[154];
		temp.y = (float) localRands[154] * temp.y + localRands[154];;
	temp.x = (float) localRands[110] * temp.x + localRands[110];
		temp.y = (float) localRands[110] * temp.y + localRands[110];;
	temp.x = (float) localRands[0] * temp.x + localRands[0];
		temp.y = (float) localRands[0] * temp.y + localRands[0];;
	temp.x = (float) localRands[139] * temp.x + localRands[139];
		temp.y = (float) localRands[139] * temp.y + localRands[139];;
	temp.x = (float) localRands[113] * temp.x + localRands[113];
		temp.y = (float) localRands[113] * temp.y + localRands[113];;
	temp.x = (float) localRands[191] * temp.x + localRands[191];
		temp.y = (float) localRands[191] * temp.y + localRands[191];;
	temp.x = (float) localRands[134] * temp.x + localRands[134];
		temp.y = (float) localRands[134] * temp.y + localRands[134];;
	temp.x = (float) localRands[10] * temp.x + localRands[10];
		temp.y = (float) localRands[10] * temp.y + localRands[10];;
	temp.x = (float) localRands[127] * temp.x + localRands[127];
		temp.y = (float) localRands[127] * temp.y + localRands[127];;
	temp.x = (float) localRands[83] * temp.x + localRands[83];
		temp.y = (float) localRands[83] * temp.y + localRands[83];;
	temp.x = (float) localRands[130] * temp.x + localRands[130];
		temp.y = (float) localRands[130] * temp.y + localRands[130];;
	temp.x = (float) localRands[224] * temp.x + localRands[224];
		temp.y = (float) localRands[224] * temp.y + localRands[224];;
	temp.x = (float) localRands[65] * temp.x + localRands[65];
		temp.y = (float) localRands[65] * temp.y + localRands[65];;
	temp.x = (float) localRands[105] * temp.x + localRands[105];
		temp.y = (float) localRands[105] * temp.y + localRands[105];;
	temp.x = (float) localRands[137] * temp.x + localRands[137];
		temp.y = (float) localRands[137] * temp.y + localRands[137];;
	temp.x = (float) localRands[164] * temp.x + localRands[164];
		temp.y = (float) localRands[164] * temp.y + localRands[164];;
	temp.x = (float) localRands[141] * temp.x + localRands[141];
		temp.y = (float) localRands[141] * temp.y + localRands[141];;
	temp.x = (float) localRands[48] * temp.x + localRands[48];
		temp.y = (float) localRands[48] * temp.y + localRands[48];;
	temp.x = (float) localRands[15] * temp.x + localRands[15];
		temp.y = (float) localRands[15] * temp.y + localRands[15];;
	temp.x = (float) localRands[148] * temp.x + localRands[148];
		temp.y = (float) localRands[148] * temp.y + localRands[148];;
	temp.x = (float) localRands[125] * temp.x + localRands[125];
		temp.y = (float) localRands[125] * temp.y + localRands[125];;
	temp.x = (float) localRands[49] * temp.x + localRands[49];
		temp.y = (float) localRands[49] * temp.y + localRands[49];;
	temp.x = (float) localRands[227] * temp.x + localRands[227];
		temp.y = (float) localRands[227] * temp.y + localRands[227];;
	temp.x = (float) localRands[155] * temp.x + localRands[155];
		temp.y = (float) localRands[155] * temp.y + localRands[155];;
	temp.x = (float) localRands[220] * temp.x + localRands[220];
		temp.y = (float) localRands[220] * temp.y + localRands[220];;
	temp.x = (float) localRands[103] * temp.x + localRands[103];
		temp.y = (float) localRands[103] * temp.y + localRands[103];;
	temp.x = (float) localRands[240] * temp.x + localRands[240];
		temp.y = (float) localRands[240] * temp.y + localRands[240];;
	temp.x = (float) localRands[8] * temp.x + localRands[8];
		temp.y = (float) localRands[8] * temp.y + localRands[8];;
	temp.x = (float) localRands[114] * temp.x + localRands[114];
		temp.y = (float) localRands[114] * temp.y + localRands[114];;
	temp.x = (float) localRands[175] * temp.x + localRands[175];
		temp.y = (float) localRands[175] * temp.y + localRands[175];;
	temp.x = (float) localRands[57] * temp.x + localRands[57];
		temp.y = (float) localRands[57] * temp.y + localRands[57];;
	temp.x = (float) localRands[143] * temp.x + localRands[143];
		temp.y = (float) localRands[143] * temp.y + localRands[143];;
	temp.x = (float) localRands[162] * temp.x + localRands[162];
		temp.y = (float) localRands[162] * temp.y + localRands[162];;
	temp.x = (float) localRands[24] * temp.x + localRands[24];
		temp.y = (float) localRands[24] * temp.y + localRands[24];;
	temp.x = (float) localRands[73] * temp.x + localRands[73];
		temp.y = (float) localRands[73] * temp.y + localRands[73];;
	temp.x = (float) localRands[235] * temp.x + localRands[235];
		temp.y = (float) localRands[235] * temp.y + localRands[235];;
	temp.x = (float) localRands[196] * temp.x + localRands[196];
		temp.y = (float) localRands[196] * temp.y + localRands[196];;
	temp.x = (float) localRands[104] * temp.x + localRands[104];
		temp.y = (float) localRands[104] * temp.y + localRands[104];;
	temp.x = (float) localRands[88] * temp.x + localRands[88];
		temp.y = (float) localRands[88] * temp.y + localRands[88];;
	temp.x = (float) localRands[59] * temp.x + localRands[59];
		temp.y = (float) localRands[59] * temp.y + localRands[59];;
	temp.x = (float) localRands[225] * temp.x + localRands[225];
		temp.y = (float) localRands[225] * temp.y + localRands[225];;
	temp.x = (float) localRands[195] * temp.x + localRands[195];
		temp.y = (float) localRands[195] * temp.y + localRands[195];;
	temp.x = (float) localRands[100] * temp.x + localRands[100];
		temp.y = (float) localRands[100] * temp.y + localRands[100];;
	temp.x = (float) localRands[238] * temp.x + localRands[238];
		temp.y = (float) localRands[238] * temp.y + localRands[238];;
	temp.x = (float) localRands[76] * temp.x + localRands[76];
		temp.y = (float) localRands[76] * temp.y + localRands[76];;
	temp.x = (float) localRands[222] * temp.x + localRands[222];
		temp.y = (float) localRands[222] * temp.y + localRands[222];;
	temp.x = (float) localRands[84] * temp.x + localRands[84];
		temp.y = (float) localRands[84] * temp.y + localRands[84];;
	temp.x = (float) localRands[80] * temp.x + localRands[80];
		temp.y = (float) localRands[80] * temp.y + localRands[80];;
	temp.x = (float) localRands[147] * temp.x + localRands[147];
		temp.y = (float) localRands[147] * temp.y + localRands[147];;
	temp.x = (float) localRands[140] * temp.x + localRands[140];
		temp.y = (float) localRands[140] * temp.y + localRands[140];;
	temp.x = (float) localRands[172] * temp.x + localRands[172];
		temp.y = (float) localRands[172] * temp.y + localRands[172];;
	temp.x = (float) localRands[245] * temp.x + localRands[245];
		temp.y = (float) localRands[245] * temp.y + localRands[245];;
	temp.x = (float) localRands[32] * temp.x + localRands[32];
		temp.y = (float) localRands[32] * temp.y + localRands[32];;
	temp.x = (float) localRands[9] * temp.x + localRands[9];
		temp.y = (float) localRands[9] * temp.y + localRands[9];;
	temp.x = (float) localRands[188] * temp.x + localRands[188];
		temp.y = (float) localRands[188] * temp.y + localRands[188];;
	temp.x = (float) localRands[78] * temp.x + localRands[78];
		temp.y = (float) localRands[78] * temp.y + localRands[78];;
	temp.x = (float) localRands[179] * temp.x + localRands[179];
		temp.y = (float) localRands[179] * temp.y + localRands[179];;
	temp.x = (float) localRands[47] * temp.x + localRands[47];
		temp.y = (float) localRands[47] * temp.y + localRands[47];;
	temp.x = (float) localRands[74] * temp.x + localRands[74];
		temp.y = (float) localRands[74] * temp.y + localRands[74];;
	temp.x = (float) localRands[91] * temp.x + localRands[91];
		temp.y = (float) localRands[91] * temp.y + localRands[91];;
	temp.x = (float) localRands[174] * temp.x + localRands[174];
		temp.y = (float) localRands[174] * temp.y + localRands[174];;
	temp.x = (float) localRands[37] * temp.x + localRands[37];
		temp.y = (float) localRands[37] * temp.y + localRands[37];;
	temp.x = (float) localRands[26] * temp.x + localRands[26];
		temp.y = (float) localRands[26] * temp.y + localRands[26];;
	temp.x = (float) localRands[221] * temp.x + localRands[221];
		temp.y = (float) localRands[221] * temp.y + localRands[221];;
	temp.x = (float) localRands[63] * temp.x + localRands[63];
		temp.y = (float) localRands[63] * temp.y + localRands[63];;
	temp.x = (float) localRands[52] * temp.x + localRands[52];
		temp.y = (float) localRands[52] * temp.y + localRands[52];;
	temp.x = (float) localRands[61] * temp.x + localRands[61];
		temp.y = (float) localRands[61] * temp.y + localRands[61];;
	temp.x = (float) localRands[31] * temp.x + localRands[31];
		temp.y = (float) localRands[31] * temp.y + localRands[31];;
	temp.x = (float) localRands[253] * temp.x + localRands[253];
		temp.y = (float) localRands[253] * temp.y + localRands[253];;
	temp.x = (float) localRands[90] * temp.x + localRands[90];
		temp.y = (float) localRands[90] * temp.y + localRands[90];;
	temp.x = (float) localRands[176] * temp.x + localRands[176];
		temp.y = (float) localRands[176] * temp.y + localRands[176];;
	temp.x = (float) localRands[187] * temp.x + localRands[187];
		temp.y = (float) localRands[187] * temp.y + localRands[187];;
	temp.x = (float) localRands[250] * temp.x + localRands[250];
		temp.y = (float) localRands[250] * temp.y + localRands[250];;
	temp.x = (float) localRands[168] * temp.x + localRands[168];
		temp.y = (float) localRands[168] * temp.y + localRands[168];;
	temp.x = (float) localRands[212] * temp.x + localRands[212];
		temp.y = (float) localRands[212] * temp.y + localRands[212];;
	temp.x = (float) localRands[111] * temp.x + localRands[111];
		temp.y = (float) localRands[111] * temp.y + localRands[111];;
	temp.x = (float) localRands[239] * temp.x + localRands[239];
		temp.y = (float) localRands[239] * temp.y + localRands[239];;
	temp.x = (float) localRands[132] * temp.x + localRands[132];
		temp.y = (float) localRands[132] * temp.y + localRands[132];;
	temp.x = (float) localRands[165] * temp.x + localRands[165];
		temp.y = (float) localRands[165] * temp.y + localRands[165];;
	temp.x = (float) localRands[186] * temp.x + localRands[186];
		temp.y = (float) localRands[186] * temp.y + localRands[186];;
	temp.x = (float) localRands[53] * temp.x + localRands[53];
		temp.y = (float) localRands[53] * temp.y + localRands[53];;
	temp.x = (float) localRands[60] * temp.x + localRands[60];
		temp.y = (float) localRands[60] * temp.y + localRands[60];;
	temp.x = (float) localRands[193] * temp.x + localRands[193];
		temp.y = (float) localRands[193] * temp.y + localRands[193];;
	temp.x = (float) localRands[236] * temp.x + localRands[236];
		temp.y = (float) localRands[236] * temp.y + localRands[236];;
	temp.x = (float) localRands[116] * temp.x + localRands[116];
		temp.y = (float) localRands[116] * temp.y + localRands[116];;
	temp.x = (float) localRands[136] * temp.x + localRands[136];
		temp.y = (float) localRands[136] * temp.y + localRands[136];;
	temp.x = (float) localRands[181] * temp.x + localRands[181];
		temp.y = (float) localRands[181] * temp.y + localRands[181];;
	temp.x = (float) localRands[158] * temp.x + localRands[158];
		temp.y = (float) localRands[158] * temp.y + localRands[158];;
	temp.x = (float) localRands[166] * temp.x + localRands[166];
		temp.y = (float) localRands[166] * temp.y + localRands[166];;
	temp.x = (float) localRands[97] * temp.x + localRands[97];
		temp.y = (float) localRands[97] * temp.y + localRands[97];;
	temp.x = (float) localRands[182] * temp.x + localRands[182];
		temp.y = (float) localRands[182] * temp.y + localRands[182];;
	temp.x = (float) localRands[214] * temp.x + localRands[214];
		temp.y = (float) localRands[214] * temp.y + localRands[214];;
	temp.x = (float) localRands[11] * temp.x + localRands[11];
		temp.y = (float) localRands[11] * temp.y + localRands[11];;
	temp.x = (float) localRands[66] * temp.x + localRands[66];
		temp.y = (float) localRands[66] * temp.y + localRands[66];;
	temp.x = (float) localRands[231] * temp.x + localRands[231];
		temp.y = (float) localRands[231] * temp.y + localRands[231];;
	temp.x = (float) localRands[223] * temp.x + localRands[223];
		temp.y = (float) localRands[223] * temp.y + localRands[223];;
	temp.x = (float) localRands[118] * temp.x + localRands[118];
		temp.y = (float) localRands[118] * temp.y + localRands[118];;
	temp.x = (float) localRands[192] * temp.x + localRands[192];
		temp.y = (float) localRands[192] * temp.y + localRands[192];;
	temp.x = (float) localRands[144] * temp.x + localRands[144];
		temp.y = (float) localRands[144] * temp.y + localRands[144];;
	temp.x = (float) localRands[17] * temp.x + localRands[17];
		temp.y = (float) localRands[17] * temp.y + localRands[17];;
	temp.x = (float) localRands[68] * temp.x + localRands[68];
		temp.y = (float) localRands[68] * temp.y + localRands[68];;
	temp.x = (float) localRands[50] * temp.x + localRands[50];
		temp.y = (float) localRands[50] * temp.y + localRands[50];;
	temp.x = (float) localRands[22] * temp.x + localRands[22];
		temp.y = (float) localRands[22] * temp.y + localRands[22];;
	temp.x = (float) localRands[183] * temp.x + localRands[183];
		temp.y = (float) localRands[183] * temp.y + localRands[183];;
	temp.x = (float) localRands[81] * temp.x + localRands[81];
		temp.y = (float) localRands[81] * temp.y + localRands[81];;
	temp.x = (float) localRands[178] * temp.x + localRands[178];
		temp.y = (float) localRands[178] * temp.y + localRands[178];;
	temp.x = (float) localRands[25] * temp.x + localRands[25];
		temp.y = (float) localRands[25] * temp.y + localRands[25];;
	temp.x = (float) localRands[128] * temp.x + localRands[128];
		temp.y = (float) localRands[128] * temp.y + localRands[128];;
	temp.x = (float) localRands[124] * temp.x + localRands[124];
		temp.y = (float) localRands[124] * temp.y + localRands[124];;
	temp.x = (float) localRands[208] * temp.x + localRands[208];
		temp.y = (float) localRands[208] * temp.y + localRands[208];;
	temp.x = (float) localRands[211] * temp.x + localRands[211];
		temp.y = (float) localRands[211] * temp.y + localRands[211];;
	temp.x = (float) localRands[87] * temp.x + localRands[87];
		temp.y = (float) localRands[87] * temp.y + localRands[87];;
	temp.x = (float) localRands[108] * temp.x + localRands[108];
		temp.y = (float) localRands[108] * temp.y + localRands[108];;
	temp.x = (float) localRands[64] * temp.x + localRands[64];
		temp.y = (float) localRands[64] * temp.y + localRands[64];;
	temp.x = (float) localRands[54] * temp.x + localRands[54];
		temp.y = (float) localRands[54] * temp.y + localRands[54];;
	temp.x = (float) localRands[41] * temp.x + localRands[41];
		temp.y = (float) localRands[41] * temp.y + localRands[41];;
	temp.x = (float) localRands[98] * temp.x + localRands[98];
		temp.y = (float) localRands[98] * temp.y + localRands[98];;
	temp.x = (float) localRands[122] * temp.x + localRands[122];
		temp.y = (float) localRands[122] * temp.y + localRands[122];;
	temp.x = (float) localRands[194] * temp.x + localRands[194];
		temp.y = (float) localRands[194] * temp.y + localRands[194];;
	temp.x = (float) localRands[71] * temp.x + localRands[71];
		temp.y = (float) localRands[71] * temp.y + localRands[71];;
	temp.x = (float) localRands[115] * temp.x + localRands[115];
		temp.y = (float) localRands[115] * temp.y + localRands[115];;
	temp.x = (float) localRands[200] * temp.x + localRands[200];
		temp.y = (float) localRands[200] * temp.y + localRands[200];;
	temp.x = (float) localRands[109] * temp.x + localRands[109];
		temp.y = (float) localRands[109] * temp.y + localRands[109];;
	temp.x = (float) localRands[202] * temp.x + localRands[202];
		temp.y = (float) localRands[202] * temp.y + localRands[202];;
	temp.x = (float) localRands[119] * temp.x + localRands[119];
		temp.y = (float) localRands[119] * temp.y + localRands[119];;
	temp.x = (float) localRands[210] * temp.x + localRands[210];
		temp.y = (float) localRands[210] * temp.y + localRands[210];;
	temp.x = (float) localRands[27] * temp.x + localRands[27];
		temp.y = (float) localRands[27] * temp.y + localRands[27];;
	temp.x = (float) localRands[13] * temp.x + localRands[13];
		temp.y = (float) localRands[13] * temp.y + localRands[13];;
	temp.x = (float) localRands[38] * temp.x + localRands[38];
		temp.y = (float) localRands[38] * temp.y + localRands[38];;
	temp.x = (float) localRands[190] * temp.x + localRands[190];
		temp.y = (float) localRands[190] * temp.y + localRands[190];;
	temp.x = (float) localRands[215] * temp.x + localRands[215];
		temp.y = (float) localRands[215] * temp.y + localRands[215];;
	temp.x = (float) localRands[72] * temp.x + localRands[72];
		temp.y = (float) localRands[72] * temp.y + localRands[72];;
	temp.x = (float) localRands[234] * temp.x + localRands[234];
		temp.y = (float) localRands[234] * temp.y + localRands[234];;
	temp.x = (float) localRands[89] * temp.x + localRands[89];
		temp.y = (float) localRands[89] * temp.y + localRands[89];;
	temp.x = (float) localRands[145] * temp.x + localRands[145];
		temp.y = (float) localRands[145] * temp.y + localRands[145];;
	temp.x = (float) localRands[255] * temp.x + localRands[255];
		temp.y = (float) localRands[255] * temp.y + localRands[255];;
	temp.x = (float) localRands[216] * temp.x + localRands[216];
		temp.y = (float) localRands[216] * temp.y + localRands[216];;
	temp.x = (float) localRands[180] * temp.x + localRands[180];
		temp.y = (float) localRands[180] * temp.y + localRands[180];;
	temp.x = (float) localRands[177] * temp.x + localRands[177];
		temp.y = (float) localRands[177] * temp.y + localRands[177];;
	temp.x = (float) localRands[12] * temp.x + localRands[12];
		temp.y = (float) localRands[12] * temp.y + localRands[12];;
	temp.x = (float) localRands[207] * temp.x + localRands[207];
		temp.y = (float) localRands[207] * temp.y + localRands[207];;
	temp.x = (float) localRands[229] * temp.x + localRands[229];
		temp.y = (float) localRands[229] * temp.y + localRands[229];;
	temp.x = (float) localRands[149] * temp.x + localRands[149];
		temp.y = (float) localRands[149] * temp.y + localRands[149];;
	temp.x = (float) localRands[107] * temp.x + localRands[107];
		temp.y = (float) localRands[107] * temp.y + localRands[107];;
	temp.x = (float) localRands[138] * temp.x + localRands[138];
		temp.y = (float) localRands[138] * temp.y + localRands[138];;
	temp.x = (float) localRands[163] * temp.x + localRands[163];
		temp.y = (float) localRands[163] * temp.y + localRands[163];;
	temp.x = (float) localRands[123] * temp.x + localRands[123];
		temp.y = (float) localRands[123] * temp.y + localRands[123];;
	temp.x = (float) localRands[86] * temp.x + localRands[86];
		temp.y = (float) localRands[86] * temp.y + localRands[86];;
	temp.x = (float) localRands[34] * temp.x + localRands[34];
		temp.y = (float) localRands[34] * temp.y + localRands[34];;
	temp.x = (float) localRands[135] * temp.x + localRands[135];
		temp.y = (float) localRands[135] * temp.y + localRands[135];;
	temp.x = (float) localRands[126] * temp.x + localRands[126];
		temp.y = (float) localRands[126] * temp.y + localRands[126];;
	temp.x = (float) localRands[189] * temp.x + localRands[189];
		temp.y = (float) localRands[189] * temp.y + localRands[189];;
	temp.x = (float) localRands[198] * temp.x + localRands[198];
		temp.y = (float) localRands[198] * temp.y + localRands[198];;
	temp.x = (float) localRands[70] * temp.x + localRands[70];
		temp.y = (float) localRands[70] * temp.y + localRands[70];;
	temp.x = (float) localRands[171] * temp.x + localRands[171];
		temp.y = (float) localRands[171] * temp.y + localRands[171];;
	temp.x = (float) localRands[19] * temp.x + localRands[19];
		temp.y = (float) localRands[19] * temp.y + localRands[19];;
	temp.x = (float) localRands[67] * temp.x + localRands[67];
		temp.y = (float) localRands[67] * temp.y + localRands[67];;
	temp.x = (float) localRands[58] * temp.x + localRands[58];
		temp.y = (float) localRands[58] * temp.y + localRands[58];;
	temp.x = (float) localRands[232] * temp.x + localRands[232];
		temp.y = (float) localRands[232] * temp.y + localRands[232];;
	temp.x = (float) localRands[237] * temp.x + localRands[237];
		temp.y = (float) localRands[237] * temp.y + localRands[237];;
	temp.x = (float) localRands[35] * temp.x + localRands[35];
		temp.y = (float) localRands[35] * temp.y + localRands[35];;
	temp.x = (float) localRands[82] * temp.x + localRands[82];
		temp.y = (float) localRands[82] * temp.y + localRands[82];;
	temp.x = (float) localRands[129] * temp.x + localRands[129];
		temp.y = (float) localRands[129] * temp.y + localRands[129];;
	temp.x = (float) localRands[170] * temp.x + localRands[170];
		temp.y = (float) localRands[170] * temp.y + localRands[170];;
	temp.x = (float) localRands[2] * temp.x + localRands[2];
		temp.y = (float) localRands[2] * temp.y + localRands[2];;
	temp.x = (float) localRands[241] * temp.x + localRands[241];
		temp.y = (float) localRands[241] * temp.y + localRands[241];;
	temp.x = (float) localRands[156] * temp.x + localRands[156];
		temp.y = (float) localRands[156] * temp.y + localRands[156];;
	temp.x = (float) localRands[233] * temp.x + localRands[233];
		temp.y = (float) localRands[233] * temp.y + localRands[233];;
	temp.x = (float) localRands[14] * temp.x + localRands[14];
		temp.y = (float) localRands[14] * temp.y + localRands[14];;
	temp.x = (float) localRands[213] * temp.x + localRands[213];
		temp.y = (float) localRands[213] * temp.y + localRands[213];;
	temp.x = (float) localRands[146] * temp.x + localRands[146];
		temp.y = (float) localRands[146] * temp.y + localRands[146];;
	temp.x = (float) localRands[173] * temp.x + localRands[173];
		temp.y = (float) localRands[173] * temp.y + localRands[173];;
	data[gid] = temp.x + temp.y;

}


void TestS2VfloatD256Form1MUnrol1U0LM1RAND_wrapper (float *data, float *rands, int index, int rand_max, int numBlocks, int threadPerBlock) {
	TestS2VfloatD256Form1MUnrol1U0LM1RAND<<<numBlocks, threadPerBlock>>> (data, rands, index, rand_max);
}

#endif 
