// Nguyen Khac Quan K56CA
// K56CA - 11020250
// Chuong 1 - Bai 19

#include <stdio.h>
#include <time.h>
#include <math.h>

const double EPSILON = 1e-3;
#define E        2.71828182845904523536

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


double f_18_1(double x){
	return pow(x, 1.0 / 3) + x - 1;
}
double f_18_2(double x){
	return log(x) - pow(E, -x);
}
double f_18_3(double x){
	return x + log(x) - 2;
}
double f_18_4(double x){
	return 2 * x - pow(E, x) + 1;
}
double f_18_5(double x){
	return x*x*x + 3 * x*x - 3;
}
double f_18_6(double x){
	return x*x*x + 3 * x*x + 18 * x - 1;
}
double f_18_7(double x){
	return x*x*x - 2 * x + 0.2;
}
double f_18_8(double x){
	return x*x*x*x + x - 3;
}
double f_18_9(double x){
	return x*x*x*x - 4*x - 1;
}
double f_19_1(double x){
	return x*x - 5 * x + 5;
}
double f_19_2(double x){
	return x*x - 5 * x + 5;
}
double f_19_3(double x){
	return x*x - 5 * x + 5;
}
double f_19_4(double x){
	return 5 * x*x*x - 20 * x + 3;
}
double f_19_5(double x){
	return x*x*x - 2 * x + 0.2;
}
double f_19_6(double x){
	return x*x*x - x - 1;
}
double f_19_7(double x){
	return x*x*x + x - 1000;
}
double f_19_8(double x){
	return pow(E, x) - x - 2;
}
double f_19_9(double x){
	return 2 * x - pow(E, x) + 1;
}


double f_dao_ham_18_1(double x){
	return 1 + pow(x, -2.0 / 3) / 3;
}
double f_dao_ham_18_2(double x){
	return pow(E, -x) + 1 / x;
}
double f_dao_ham_18_3(double x){
	return 1 + 1 / x;
}
double f_dao_ham_18_4(double x){
	return 2 - pow(E, x);
}
double f_dao_ham_18_5(double x){
	return 3 * x*x + 6 * x;
}
double f_dao_ham_18_6(double x){
	return 3 * x*x + 6 * x + 18;
}
double f_dao_ham_18_7(double x){
	return 3 * x*x - 2;
}
double f_dao_ham_18_8(double x){
	return 4 * x*x*x + 1;
}
double f_dao_ham_18_9(double x){
	return 4 * x*x*x -4;
}
double f_dao_ham_19_1(double x){
	return 2 * x - 5;
}
double f_dao_ham_19_2(double x){
	return 2 * x - 5;
}
double f_dao_ham_19_3(double x){
	return 2 * x - 5;
}
double f_dao_ham_19_4(double x){
	return 15 * x*x - 20;
}
double f_dao_ham_19_5(double x){
	return 3 * x*x - 2;
}
double f_dao_ham_19_6(double x){
	return 3 * x*x - 1;
}
double f_dao_ham_19_7(double x){
	return 3 * x*x + 1;
}
double f_dao_ham_19_8(double x){
	return pow(E, x) - 1;
}
double f_dao_ham_19_9(double x){
	return 2 - pow(E, x);
}


double phi_18_1(double x){
	return 1 - pow(x, 1.0 / 3); // x = (1 - x)^3
}
double phi_18_2(double x){
	return pow(E, pow(E, -x));
}
double phi_18_3(double x){
	return 2 - log(x);
}
double phi_18_4(double x){
	return log(2 * x + 1);
}
double phi_18_5(double x){
	return 3 / x / x - 3;
}
double phi_18_6(double x){
	return (1 - x*x*x - 3 * x*x) / 18;
}
double phi_18_7(double x){
	return pow(2 * x - 0.2, 1.0 / 3);
}
double phi_18_8(double x){
	return pow(3 - x, 0.25);
}
double phi_18_9(double x){
	return (x*x*x*x - 1) / 4;
}
double phi_19_1(double x){
	return x*x / 5 + 1;
}
double phi_19_2(double x){
	return 5.0 / (5.0 - x);
}
double phi_19_3(double x){
	return 4 - 1.0 / (x - 1);
}
double phi_19_4(double x){
	return (5 * x*x*x + 3) / 20;
}
double phi_19_5(double x){
	return pow(2 * x - 0.2, 1.0 / 3);
}
double phi_19_6(double x){
	return pow(x + 1, 1.0 / 3);
}
double phi_19_7(double x){
	return pow(1000 - x, 1.0 / 3);
}
double phi_19_8(double x){
	return log(x + 2);
}
double phi_19_9(double x){
	return log(2 * x + 1);
}





struct SData{
	double a, b;
	double(*f)(double); // y(x)
	double(*f_dao_ham)(double);
	double(*phi)(double);
};

void PhuongPhapLap(struct SData data, double absoluteError){
	double(*phi)(double) = data.phi;
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int iStep = 0;
	double error, a, b, x, nextX;
	a = data.a < data.b ? data.a : data.b;
	b = data.a < data.b ? data.b : data.a;
	x = (a + b) / 2;

	do
	{
		iStep++;
		nextX = phi(x);
		error = myAbs(x - nextX);
		x = nextX;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("\t\tRunning time (ms): %10.5f\n", time_spent);
	printf("\t\tNumber of repeat steps: %d\n", iStep);
	char s[100];
	sprintf(s, "\t\tValue of x(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, x);
}

void PhuongPhapChiaDoi(struct SData data, double absoluteError){
	double(*f)(double) = data.f;
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int iStep = 0;
	double error, a, b, x;
	a = data.a < data.b ? data.a : data.b;
	b = data.a < data.b ? data.b : data.a;
	do
	{
		iStep++;
		x = (a + b) / 2.0;
		if (f(a)*f(x) < 0)
			b = x;

		else if (f(a)*f(x) > 0){
			a = x;
		}
		else
		{
			b = a = x;
		}
		error = b - a;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("\t\tRunning time (ms): %10.5f\n", time_spent);
	printf("\t\tNumber of repeat steps: %d\n", iStep);
	char s[100];
	sprintf(s, "\t\tValue of x(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, x);
}

void PhuongPhapTiepTuyen(struct SData data, double absoluteError){
	double(*f)(double) = data.f;
	double(*f_dao_ham)(double) = data.f_dao_ham;
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int iStep = 0;
	double error, a, b, x, x2;
	a = data.a < data.b ? data.a : data.b;
	b = data.a < data.b ? data.b : data.a;
	x = (a + b) / 2.0;
	do
	{
		iStep++;
		x2 = x - f(x) / f_dao_ham(x);
		error = myAbs(x-x2);
		x = x2;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("\t\tRunning time (ms): %10.5f\n", time_spent);
	printf("\t\tNumber of repeat steps: %d\n", iStep);
	char s[100];
	sprintf(s, "\t\tValue of x(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, x);
}

void PhuongPhapDayCung(struct SData data, double absoluteError){
	double(*f)(double) = data.f;
	clock_t begin, end;
	double time_spent;
	begin = clock();
	int iStep = 0;
	double error, a, b, x, x2;
	a = data.a < data.b ? data.a : data.b;
	b = data.a < data.b ? data.b : data.a;
	x = (a*f(b) - b*f(a)) / (f(b) - f(a)) + 1;
	if (x > b)
		x = b;
	do
	{
		iStep++;
		x2 = (a*f(b)-b*f(a)) / (f(b)-f(a));
		if (f(a)*f(x2) < 0)
			b = x2;
		else if (f(a)*f(x2) > 0){
			a = x2;
		}
		else
		{
			b = a = x2;
		}
		error = myAbs(x - x2);
		x = x2;
	} while (error > absoluteError);
	end = clock();
	time_spent = (double)(end - begin);

	printf("\t\tRunning time (ms): %10.5f\n", time_spent);
	printf("\t\tNumber of repeat steps: %d\n", iStep);
	char s[100];
	sprintf(s, "\t\tValue of x(%%d): %%.%df\n", getPerciseDigit(absoluteError));
	printf(s, iStep, x);
}


void ModifyData(struct SData *data, double a, double b, double(*f)(double), double(*f_dao_ham)(double), double(*phi)(double)){
	data->a = a;
	data->b = b;
	data->f = f;
	data->f_dao_ham = f_dao_ham;
	data->phi = phi;
}

int main(int argc, char* argv[])
{
	struct SData data[2][9];
	ModifyData(&data[0][0], 0, 1, f_18_1, f_dao_ham_18_1, phi_18_1);
	ModifyData(&data[0][1], 1, 2, f_18_2, f_dao_ham_18_2, phi_18_2);
	ModifyData(&data[0][2], 1, 2, f_18_3, f_dao_ham_18_3, phi_18_3);
	ModifyData(&data[0][3], 1, 2, f_18_4, f_dao_ham_18_4, phi_18_4);
	ModifyData(&data[0][4], -3, -2, f_18_5, f_dao_ham_18_5, phi_18_5);
	ModifyData(&data[0][5], 0, 1, f_18_6, f_dao_ham_18_6, phi_18_6);
	ModifyData(&data[0][6], 1, 2, f_18_7, f_dao_ham_18_7, phi_18_7);
	ModifyData(&data[0][7], 1, 2, f_18_8, f_dao_ham_18_8, phi_18_8);
	ModifyData(&data[0][8], -1, 0, f_18_9, f_dao_ham_18_9, phi_18_9);

	ModifyData(&data[1][0], 1, 1.5, f_19_1, f_dao_ham_19_1, phi_19_1);
	ModifyData(&data[1][1], 1, 1.5, f_19_2, f_dao_ham_19_2, phi_19_2);
	ModifyData(&data[1][2], 3, 4, f_19_3, f_dao_ham_19_3, phi_19_3);
	ModifyData(&data[1][3], 0, 1, f_19_4, f_dao_ham_19_4, phi_19_4);
	ModifyData(&data[1][4], 1, 2, f_19_5, f_dao_ham_19_5, phi_19_5);
	ModifyData(&data[1][5], 1, 2, f_19_6, f_dao_ham_19_6, phi_19_6);
	ModifyData(&data[1][6], 9, 10, f_19_7, f_dao_ham_19_7, phi_19_7);
	ModifyData(&data[1][7], 1, 2, f_19_8, f_dao_ham_19_8, phi_19_8);
	ModifyData(&data[1][8], 1, 2, f_19_9, f_dao_ham_19_9, phi_19_9);
	double absoluteError = EPSILON;
	inputError(&absoluteError);

	int i, j;
	for (j = 0; j < 2; j++){
		for (i = 0; i < 9; i++){
			printf("\nProblem %d.%d:\n", j + 18, i + 1);
			printf("\tPhuong Phap Lap:\n");
			PhuongPhapLap(data[j][i], absoluteError);
			printf("\tPhuong Phap Chia doi:\n");
			PhuongPhapChiaDoi(data[j][i], absoluteError);
			printf("\tPhuong Phap Tiep tuyen:\n");
			PhuongPhapTiepTuyen(data[j][i], absoluteError);
			printf("\tPhuong Phap Day cung:\n");
			PhuongPhapDayCung(data[j][i], absoluteError);
			printf("\n\n\n");
			if (i % 4 == 0 && i > 0)system("pause");
		}
	}
}
