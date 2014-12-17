// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 3
// S(n) = Sum of 1/(n+k) k =1..n; n to infinite

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

double Bai3_S(int n){
	double result = 0;
	int k;
	for (k = 1; k <= n; k++){
		result += 1.0 / (n + k);
	}
	return result;
}

// return S(n+1) - S(n) = 1/(2n+2) + 1/(2n+1) - 1/(n+1)
double Bai3_DeltaS(int n){
	double t = 1.0 / (2 * n + 1) + 1.0 / (2 * n + 2) - 1.0 / (n + 1);
	if (t > 0)
		return t;
	else
		return -t;
}


int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai3_S;	// Ham tinh S(n)
	double(*DeltaS)(int) = Bai3_DeltaS; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 1;
	inputError(&absoluteError);
	begin = clock();
	int iStep = initN - 1;
	do
	{
		iStep++;
	} while (DeltaS(iStep) > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("Running time (ms): %10.5f\n", time_spent);
	printf("Number of repeat steps: %d\n", iStep - initN);
	char s[100];
	sprintf(s, "Value of S(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, TinhS(iStep));
	system("pause");
}

