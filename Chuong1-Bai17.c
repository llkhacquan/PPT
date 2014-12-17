// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 17
// 0.5772156649015328606065120900824024310421

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

double Bai17_C(int n){
	double sum = 0;
	int i;
	for (i = 1; i <= n; i++){
		sum += 1.0 / i;
	}
	return sum - log((double)n);
}


double Bai17_DeltaC(int n){
	double error;
	error = 1.0 / (n + 1) - log(n + 1.0) + log((double)n);
	return myAbs(error);
}


int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai17_C;	// Ham tinh S(n)
	double(*CalculateError)(int) = Bai17_DeltaC; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 1;
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
