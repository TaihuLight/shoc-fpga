//
// (c) August 1, 2018 Saman Biookaghazadeh @ Arizona State University
//

// Mainly for S1119 test case and other thing like that

#define AInit(A,B,C) DTYPE tempA = 0; DTYPE tempB = B; DTYPE tempC = C
#define AFinal(A) A = tempA

#define Afunction(A,B,C) AInit (A, B, C); tempA = pow(tempB,tempC); AFinal (A)
#define Afunction2(A,B,C) AInit (A, B, C); tempA = pow(tempB,tempC); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction3(A,B,C) AInit (A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction4(A,B,C) AInit(A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction5(A,B,C) AInit(A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction6(A,B,C) AInit(A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction7(A,B,C) AInit(A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)
#define Afunction8(A,B,C) AInit(A, B, C); tempA = pow(tempB, tempC); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); tempA = pow(tempB, tempA); AFinal(A)

#define Bfunction(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; AFinal (A)
#define Bfunction2(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction3(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction4(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction5(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction6(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction7(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
#define Bfunction8(A,B,C) AInit(A, B, C); tempA = cos(tempB) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; tempA = cos(tempA) * tempC; AFinal(A)
