#include"Newton.h"
int main()
{
	double x10 = 3, x20 = 2, e1 = 1E-9, e2 = 1E-9, NIT = 1000;
	double x[N];
	double M = 0;
	double n1, n2;
	double F[N];
	double x_[N];
	double x_prir[N];
	double u[N] = { 0 };
	double m = 0;
	double xlast[N];
	double xk1[N];
	double xk2[N];
	double J[N][N];

	xk1[0] = 1; xk1[1] = -1;
	xk2[0] = -1; xk2[1] = 1;
	x[0] = xk1[0]; x[1] = xk1[1];
	for (int k = 0;; k++)
	{


		F[0] = -F1(x); F[1] = -F2(x);
		J[0][0] = dF1_dx1(x);
		J[0][1] = dF1_dx2(x);
		J[1][0] = dF2_dx1(x);
		J[1][1] = dF2_dx2(x);
		xlast[0] = x[0];
		xlast[1] = x[1];
		Gauss(x_, J, F);
		x[0] += x_[0];
		x[1] += x_[1];
		n1 = abs(max(F1(x), F2(x)));
		for (int j = 0; j < N; j++)
		{
			if (x[j] < 1)
			{

				n2 = abs((x[j] - xlast[j]));

			}


			if (x[j] >= 1)
			{

				n2 = abs((x[j] - xlast[j]) / abs(x[j]));


			}
			if (n2 > m)
				m = n2;
		}
		n2 = m;
		m = 0;

		if (n1 < e1 && n2 < e2)
		{
			cout << " n1 = " << n1 << endl;
			cout << " n2 = " << n2 << endl;
			cout << " Iter = " << k + 1 << endl;
			cout << " Number of Iterations  " << k + 1 << endl << " x1 = " << x[0] << endl << " x2 = " << x[1];
			break;
		}
		if (k >= NIT)
		{
			cout << endl << " IER = 2";
			break;
		}
	}
	x[0] = xk1[0]; x[1] = xk1[1];
	m = 0;
	cout << endl << " M = ";
	cin >> M;
	for (int k = 0;; k++)
	{
		x_prir[0] = abs(M);

		x_prir[1] = abs(M);

		F[0] = -F1(x); F[1] = -F2(x);

		u[0] = x[0] + x_prir[0];
		u[1] = x_prir[1];


		J[0][0] = (F1(u) - F1(x)) / x_prir[0];

		J[1][0] = (F2(u) - F2(x)) / x_prir[0];

		u[0] = x[0];
		u[1] = x[1] + x_prir[1];

		J[0][1] = (F1(u) - F1(x)) / x_prir[1];

		J[1][1] = (F2(u) - F2(x)) / x_prir[1];


		xlast[0] = x[0];
		xlast[1] = x[1];
		Gauss(x_, J, F);
		x[0] += x_[0];
		x[1] += x_[1];
		n1 = max(abs(F1(x)), abs(F2(x)));
		for (int j = 0; j < N; j++)
		{
			if (x[j] < 1)
			{

				n2 = abs((x[j] - xlast[j]));

			}


			if (x[j] >= 1)
			{

				n2 = abs((x[j] - xlast[j]) / abs(x[j]));


			}
			if (n2 > m)
				m = n2;
		}
		n2 = m;
		m = 0;

		if (n1 < e1 && n2 < e2)
		{
			cout << " n1 = " << n1 << endl;
			cout << " n2 = " << n2 << endl;
			cout << " Iter = " << k + 1 << endl;
			cout << " Number of Iterations  " << k + 1<< endl << " x1 = " << x[0] << endl << " x2 = " << x[1];
			break;
		}
		if (k >= NIT)
		{
			cout << endl << " IER = 2";
			break;
		}
	}
}