// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 7
// pi = 2 * multiple of (4nn/(4nn-1)) from 1 to infinite

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

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double absoluteError = EPSILON;
	inputError(&absoluteError);
	begin = clock();
	int iStep = 0;
	double lastPi = 2, nextPi;

	double error = 0;
	do
	{
		iStep++;
		nextPi = lastPi * (4.0 * iStep*iStep) / (4 * iStep*iStep - 1);
		error = nextPi - lastPi;
		lastPi = nextPi;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("Running time (ms): %10.5f\n", time_spent);
	printf("Number of repeat steps: %d\n", iStep);
	char s[100];
	sprintf(s, "Value of S(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, lastPi);
	system("pause");
}

