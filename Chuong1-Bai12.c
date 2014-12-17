// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 12
//

#include <stdio.h>
#include <time.h>
#include <math.h>

const double EPSILON = 1e-5;
#define MAX_FACTORIAL 1000

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

double factorial[MAX_FACTORIAL];
double CalculateFactorial(int n){
	if (n == 0){
		factorial[n] = 1;
	}
	if (factorial[n] == 0)
		factorial[n] = n*CalculateFactorial(n - 1);
	return factorial[n];
}

double part(int i)
{
	return (CalculateFactorial(4 * i) *(1103 + 26390 * i) / (pow(CalculateFactorial(i)*pow(396, i), 4)));
}

double Bai12_Pi(int n){
	double result = 0;
	int i;
	for (i = 0; i <= n; i++){
		result += part(i);
	}
	double pi = 9801.0 / result / pow(8, 0.5);
	return pi;
}

double Bai12_DeltaPi(int n){
	return myAbs(Bai12_Pi(n + 1) - Bai12_Pi(n));
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai12_Pi;	// Ham tinh S(n)
	double(*CalculateError)(int) = Bai12_DeltaPi; // Ham tinh delta S = S(n+1)- S(n)
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

