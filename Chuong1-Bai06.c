// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 6

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

double Bai6_S(int n){
	return pow(1+1.0/n, n);
}

double Bai6_DeltaS(int n){
	return 3.0 / n;
}

void inputError(double *pError){
	printf("Input absolute error: ");
	scanf("%lf", pError);
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai6_S;	// Ham tinh S(n)
	double(*DeltaS)(int) = Bai6_DeltaS; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 0;
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

