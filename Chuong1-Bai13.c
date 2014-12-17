// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 13
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
double CalculateDoubleFactorial(int n){
	if (n <= 1){
		factorial[n] = 1;
	}
	if (factorial[n] == 0)
		factorial[n] = n * CalculateDoubleFactorial(n - 2);
	return factorial[n];
}

// Tinh theo cach nay max n la 150
double Bai13_Pi(int n){
	double pi;
	pi = 2 * pow(CalculateDoubleFactorial(2 * n) / CalculateDoubleFactorial(2 * n - 1), 2) / (2.0 * n + 1.0);
	return pi;
}


double calculateT(int n){
	double result = 1, i;
	for (i = 2; i <= 2*n; i=i+2){
		result *= i / (i - 1);
	}
	return result;
}

double Bai13_Pi_2(int n){
	double pi;
	pi = 2 * pow(calculateT(n), 2) / (2.0 * n + 1.0);
	return pi;
}

double Bai13_DeltaPi(int n){
	return myAbs(Bai13_Pi_2(n + 1) - Bai13_Pi_2(n));
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai13_Pi_2;	// Ham tinh S(n)
	double(*CalculateError)(int) = Bai13_DeltaPi; // Ham tinh delta S = S(n+1)- S(n)
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

