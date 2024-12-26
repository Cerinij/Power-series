#include <iostream>
#include <clocale>
#include <chrono>
#include <cmath>
#include <iomanip>

using namespace std;
using namespace chrono;

double func(double x)
{
	return (pow(exp(1), x) + pow(exp(1), -x)) / 2;
}

int factorial(int n)
{
	int fact_res = 1;
	for (int i = 2; i <= n; i++)
	{
		fact_res *= i;
	}
	return fact_res;
}


double power_series(double x, int n, int stop)
{
	if (n > stop)
	{
		return 0;
	}
	else
	{
		return (pow(x, 2 * n) / factorial(2 * n)) + power_series(x, n + 1, stop);
	}
}

double power_series_e(double x, int n, int stop, double epsilon)
{
	if (n > stop)
	{
		return 0;
	}
	else
	{
		if (power_series(x, n + 1, stop) < epsilon)
		{
			return 0;
		}
		else
		{
			return (pow(x, 2 * n) / factorial(2 * n)) + power_series(x, n + 1, stop);
		}
	}
}

int main()
{
	double epsilon = 0.0001;
	double a = 0.1, b = 1.0;
	int k = 10, n = 10;
	double step = (b - a) / k;
	setlocale(LC_ALL, "ru");
	auto start = steady_clock::now();
	
	cout << fixed << setprecision(6);
	while (a <= b)
	{
		cout << "x = " << a << "; Sn = " << power_series(a, 0, n) << "; Se = " << power_series_e(a, 0, n, epsilon) << "; y = " << func(a) << endl;
		a += step;
	}


	auto stop = steady_clock::now();
	auto result = duration_cast<duration<double>>(stop - start).count();
	cout << "Время выполнения: " << result << endl;
	return 0;
}
