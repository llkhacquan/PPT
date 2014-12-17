// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 8
// 

#include <stdio.h>
#include <time.h>
#include <math.h>

const double EPSILON = 1e-5;

// Tinh so chu so tuong ung voi sai so
int getPerciseDigit(double dError){
	double log = -log10(dError);
	if ((double)((int)(log)) == log)
		return (int)log;
	else
		return (int)log + 1;
}

void inputError(double *pError){
	printf("Input absolute error: ");
	scanf("%lf", pError);
}

double myAbs(double x){
	return x >= 0 ? x : -x;
}

double lastPiSquare = 0.0;

double Bai8_Pi(int n){
	return sqrt(lastPiSquare);
}

double Bai8_SquareOfPi(int n){
	if (n<=0){ 
		lastPiSquare = 0;
		return 0;
	}
	else {
		lastPiSquare += 6.0 / (n * n);
		return lastPiSquare;
	}

}

double Bai8_DeltaPi(int n){
	if (n <= 0)
		return 1;
	return myAbs(sqrt(lastPiSquare) - sqrt(Bai8_SquareOfPi(n)));
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai8_Pi;	// Ham tinh S(n)
	double(*CalculateError)(int) = Bai8_DeltaPi; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 0;
	inputError(&absoluteError);
	begin = clock();
	int iStep = initN - 1;
	do
	{
		iStep++;
	} while (CalculateError(iStep) > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("Running time (ms): %10.5f\n", time_spent);
	printf("Number of repeat steps: %d\n", iStep - initN);
	char s[100];
	sprintf(s, "Value of S(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, TinhS(iStep));
	system("pause");
}

