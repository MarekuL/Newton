#include"Newton.h"
double F1(double x[N])
{
	return (cos(0.4*x[1]+pow(x[0],2)) + pow(x[1], 2)+ pow(x[0], 2) - 1.6);
}

double max(double a, double b)
{
	if (a > b)
		return a;
	else return b;
}
double F2(double x[N])
{
	return (1.5*pow(x[0],2) - (pow(x[1], 2))/0.36 - 1);
}
double dF1_dx1(double x[N])
{
	return (-2*x[0]*sin(0.4*x[1]+ pow(x[0], 2)) + 2*x[0]);
}
double dF1_dx2(double x[N])
{
	return (-(2* sin(0.4 * x[1] + pow(x[0], 2)))/5 + 2*x[1]);
}
double dF2_dx1(double x[N])
{
	return (3*x[0]);
}
double dF2_dx2(double x[N])
{
	return (-(50*x[1])/9);
}
void Gauss(double x[N], double J[N][N], double b[N])
{
	double d = 0; double s = 0;
	for (int k = 0; k < N; k++)

	{
		for (int i = k; i < N; i++)
		{

			if (abs(J[i][k]) > abs(J[k][k]))
			{
				for (int j = 0; j < N; j++)
				{
					swap(J[k][j], J[i][j]);
				}
				swap(b[k], b[i]);
			}
		}
		for (int j = k + 1; j < N; j++)

		{

			d = J[j][k] / J[k][k];

			for (int i = k; i < N; i++)

			{

				J[j][i] = J[j][i] - d * J[k][i];

			}

			b[j] = b[j] - d * b[k];

		}

	}

	for (int k = N - 1; k >= 0; k--)

	{

		d = 0;

		for (int j = k + 1; j < N; j++)

		{

			s = J[k][j] * x[j];

			d = d + s;

		}
		x[k] = 0;
		x[k] = (b[k] - d) / J[k][k];

	}
}

