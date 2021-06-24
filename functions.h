#pragma once
#include<iostream>
#include<vector>
#include<math.h>

#define M_PI 3.14159265358979323846

double m1(double y)
{
    return 0;
}

double m2(double y)
{
    return 0;
}

double m3(double x)
{
    return pow(sin(M_PI * x), 2);
}

double m4(double x)
{
    return cosh((x - 1) * (x - 2)) - 1;
}

double m1_test(double y)
{
	return exp(1 - pow(y, 2));
}

double m2_test(double y)
{
	return exp(4 - pow(y, 2));
}

double m3_test(double x)
{
	return exp(pow(x, 2) - 1);
}

double m4_test(double x)
{
	return exp(pow(x, 2) - 4);
}

double function(double x, double y)
{
	return -1 * atan(x / y);
}

double function_test(double x, double y)
{
	return 4 * exp(pow(x, 2) - pow(y, 2)) * (pow(x, 2) + pow(y, 2));
}

double U(double x, double y)
{
	return exp(pow(x, 2) - pow(y, 2));
}

void BorderConditions(std::vector<std::vector<double>> &V, int m, int n, double a, double b, double c, double d, char test)
{
    double h = (b - a) / (double)n;
    double k = (d - c) / (double)m;

    for (int i = 0; i < n + 1; i++)
    {
		if(test == 't')
			V[0][i] = m3_test(a + i * h);
		else
			V[0][i] = m3(a + i * h);
    }
    for (int i = 0; i < n + 1; i++)
    {
		if (test == 't')
			V[m][i] = m4_test(a + i * h);
		else
			V[m][i] = m4(a + i * h);
    }
    for (int j = 0; j < m + 1; j++)
    {
		if (test == 't')
			V[j][0] = m1_test(c + j * k);
		else
			V[j][0] = m1(c + j * k);
    }
    for (int j = 0; j < m + 1; j++)
    {
		if (test == 't')
			V[j][n] = m2_test(c + j * k);
		else
			V[j][n] = m2(c + j * k);
    }
    for (int j = 1; j < m; j++)
        for (int i = 1; i < n; i++)
            V[j][i] = 0;
}

void U_test(std::vector<std::vector<double>>& V, int m, int n, double a, double b, double c, double d)
{
	double h = (b - a) / (double)n;
	double k = (d - c) / (double)m;

	for (int j = 0; j < m + 1; j++)
		for (int i = 0; i < n + 1; i++)
			V[j][i] = U(a + i * h, c + j * k);
}

double EpsInMainTask(std::vector<std::vector<double>> V, std::vector<std::vector<double>> V2)
{
	int m = V.size(), n = V[0].size();
	if (m > V2.size())
	{
		m = V2.size();
		n = V2[0].size();
	}
	double res = 0, res_temp = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			res_temp = abs(V2[2 * i][2 * j] - V[i][j]);
			if (res < res_temp)
				res = res_temp;
		}
	}
	return res;
}

double EpsInTestTask(std::vector<std::vector<double>> V, std::vector<std::vector<double>> U)
{
	double res = 0, res_temp = 0;

	for (int i = 0; i < V.size(); i++)
	{
		for (int j = 0; j < V[0].size(); j++)
		{
			res_temp = abs(U[i][j] - V[i][j]);
			if (res < res_temp)
				res = res_temp;
		}
	}
	return res;
}

struct answer {
	double eps = 0;
	double tau = 0;
	int Niter = 0;
	double time = 0;
	double time_iter = 0;
	std::vector<std::vector<double>> V;
};

answer Task(double a, double b, double c, double d, int n, int m, int Nmax, double eps, char test)
{
	int S = 0;
	double eps_max = 0, eps_cur = 0;
	double h = static_cast<double>(b - a) / n;
	double k = static_cast<double>(d - c) / m;
	double h2 = - h * h, k2 = - k * k;
	double A = -2 * (1 / h2 + 1 / k2);
	double lmin = -4 / h2 * pow(sin(M_PI / 2.0 * n), 2) - 4 / k2 * pow(sin(M_PI / 2.0 * m), 2);
	double lmax = -4 / h2 * pow(cos(M_PI / 2.0 * n), 2) - 4 / k2 * pow(cos(M_PI / 2.0 * m), 2);
	double tau = 2 / (lmax + lmin);
	double v_old, v_new;
	std::vector<std::vector<double>> V, F, r;
	V.assign(m + 1, std::vector<double>(n + 1));
	r.assign(m, std::vector<double>(n));

	BorderConditions(V, m, n, a, b, c, d, test);

	double(*func)(double, double);

	if (test == 't')
		func = function_test;
	else
		func = function;

	time_t t = clock();

	do
	{
		eps_max = 0;

		for (int j = 1; j < m; j++)
			for (int i = 1; i < n; i++)
				r[j - 1][i - 1] = V[j][i] * A + (V[j][i + 1] + V[j][i - 1]) / h2 + (V[j + 1][i] 
					+ V[j - 1][i]) / k2 + func(a + i * h, c + j * k);

		for (int j = 1; j < m; j++)
		{
			for (int i = 1; i < n; i++)
			{
				v_old = V[j][i];
				V[j][i] = v_old - tau * r[j - 1][i - 1];
				eps_cur = abs(V[j][i] - v_old);
				if (eps_cur > eps_max)
					eps_max = eps_cur;
			}
		}

		S++;
	} while (eps_max > eps && S < Nmax);

	t = clock() - t;

	answer res;

	res.eps = eps_max;
	res.Niter = S;
	res.tau = tau;
	res.time = t;
	res.time_iter = static_cast<double>(t) / S;
	res.V = V;

	return res;
}


double SetParametrs(std::vector<std::vector<double>>& H, std::vector<std::vector<double>>& R, double h2,
	double k2, double A, int m, int n, double &Ahh)
{
	double betta = 0;
	double alpha = 0;
	double temp = 0, res = 0;
	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
			res = A * H[j - 1][i - 1] + (H[j - 1][i] + H[j - 1][i]) / h2 + (H[j][i - 1] + H[j][i - 1]) / k2;
			temp += res * R[j - 1][i - 1];
		}

	betta = temp / Ahh;

	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
			H[j - 1][i - 1] = R[j - 1][i - 1] * (-1) + H[j - 1][i - 1] * betta;
		}


	Ahh = 0; temp = 0;
	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
		{
			res = A * H[j - 1][i - 1] + (H[j - 1][i] + H[j - 1][i]) / h2 + (H[j][i - 1] + H[j][i - 1]) / k2;
			temp += R[j - 1][i - 1] * H[j - 1][i - 1];
			Ahh += res * H[j - 1][i - 1];
		}
	alpha = -temp / Ahh;

	return alpha;
}


answer TaskGrad(double a, double b, double c, double d, int n, int m, int Nmax, double eps, char test)
{
	int S = 0;
	double eps_max = 0, eps_cur = 0;
	double h = static_cast<double>(b - a) / n;
	double k = static_cast<double>(d - c) / m;
	double h2 = -h * h, k2 = -k * k;
	double A = -2 * (1 / h2 + 1 / k2);
	double v_old, v_new;
	std::vector<std::vector<double>> V, r, H;
	V.assign(m + 1, std::vector<double>(n + 1));
	r.assign(m, std::vector<double>(n));
	H.assign(m, std::vector<double>(n));
	double alpha, Ahh = 1;
	bool flag = false;

	BorderConditions(V, m, n, a, b, c, d, test);

	double(*func)(double, double);

	if (test == 't')
		func = function_test;
	else
		func = function;

	time_t t = clock();

	do
	{
		eps_max = 0;

		for (int j = 1; j < m; j++)
			for (int i = 1; i < n; i++)
			{
				r[j - 1][i - 1] = V[j][i] * A + (V[j][i + 1] + V[j][i - 1]) / h2 + (V[j + 1][i]
					+ V[j - 1][i]) / k2 + func(a + i * h, c + j * k);
			}

		alpha = SetParametrs(H, r, h2, k2, A, m, n, Ahh);
		for (int j = 1; j < m; j++)
		{
			for (int i = 1; i < n; i++)
			{
			
				v_old = V[j][i];
				V[j][i] = v_old + alpha * H[j - 1][i - 1];
				eps_cur = abs(V[j][i] - v_old);
				if (eps_cur > eps_max)
					eps_max = eps_cur;
			}
		}

		S++;
	} while (eps_max > eps && S < Nmax);

	t = clock() - t;

	answer res;

	res.eps = eps_max;
	res.Niter = S;
	res.time = t;
	res.time_iter = static_cast<double>(t) / S;
	res.V = V;

	return res;
}
