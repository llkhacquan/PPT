// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 16

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

double myAbs(double x){
	return x >= 0 ? x : -x;
}

void inputError(double *pError){
	printf("Input absolute error: ");
	scanf("%lf", pError);
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double absoluteError = EPSILON; // sai so tuyet doi
	int initN = 1;
	inputError(&absoluteError);
	begin = clock();
	int iStep = initN - 1;
	double error = 1, x, y, pi, nextPi;

	x = sqrt(2);
	y = pow(2, 0.25);
	nextPi = pi = 2 + sqrt(2);
	do
	{
		iStep++;
		x = (sqrt(x) + 1.0 / sqrt(x)) / 2.0; //x1
		nextPi = pi* (x + 1) / (y + 1);
		y = (y*sqrt(x) + 1.0 / sqrt(x)) / (y + 1);
		error = myAbs(nextPi - pi);
		pi = nextPi;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("Running time (ms): %10.5f\n", time_spent);
	printf("Number of repeat steps: %d\n", iStep - initN);
	char s[100];
	sprintf(s, "Value of S(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, pi);
	system("pause");
}