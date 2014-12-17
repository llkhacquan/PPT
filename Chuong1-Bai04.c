// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 4
// e = n / pow (n!, 1/n)

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

double lastE = 1;

double Bai4_S(int n){
	if (n <= 1){
		lastE = 1;			
		return lastE;
	}
	lastE = pow(lastE, (double)n / (n + 1))*(n + 1) / pow(n, (double)n / (n + 1)) / pow(n + 1, 1.0 / (n + 1));
	return lastE;
}

double Bai4_DeltaS(int n){
	static double lastE_;
	lastE_ = lastE;
	double delta = Bai4_S(n + 1) - lastE_;
	if (delta > 0)
		return delta;
	else
		return -delta;
}

void inputError(double *pError){
	printf("Input absolute error: ");
	scanf("%lf", pError);
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	double time_spent;
	double(*TinhS)(int) = Bai4_S;	// Ham tinh S(n)
	double(*DeltaS)(int) = Bai4_DeltaS; // Ham tinh delta S = S(n+1)- S(n)
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