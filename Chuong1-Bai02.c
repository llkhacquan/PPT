// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 5
// Dap so: S(n) = (n+1)/(2n) ~ 0.5
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

double Bai2_S(int n){
	return (n + 1.0) / 2.0 / n;
}

double Bai2_DeltaS(int n){
	double t = Bai2_S(n + 1) - Bai2_S(n);
	if (t > 0)
		return t;
	else return - t;
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai2_S;	// Ham tinh S(n)
	double(*DeltaS)(int) = Bai2_DeltaS; // Ham tinh delta S = S(n+1)- S(n)
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 2;
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

