#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

bool converge(double* xk, double *xkp,int size)
{
	double eps = 0.0001;
	double norm = 0;
	bool a;
	for (int i = 0; i < size; i++)
		norm += (xk[i] - xkp[i])*(xk[i] - xkp[i]);
	 a=(sqrt(norm) < eps);
	 return a;
}

int main() {
	double** A, * y;
	int size=100;
	//cout << "Enter size(100)" << endl;
	//cin >> size;
	y = new double[size];
	A = new double* [size];
		for (int i = 0; i, i < size; i++) {
		A[i] = new double[size];
		for (int j = 0; j < size; j++) {
			A[i][j] = 0;
			A[0][0] = 30;
			if (j < 5) {
				A[0][j] = 1;
			}
			else { A[0][j] = 0; }
			if (i == j) A[i][j] = 30;
		}
	}
	for (int i = 0; i, i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == 30) {
				int k = 1;
				while ((j - k) >= 0 && k <= 4) {
					A[i][j - k] = 1;
					k++;
				}
			}
		}
	}
	for (int i = 0; i, i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == 30) {
				int k = 1;
				while ((j + k) < size && k <= 4) {
					A[i][j + k] = 1;
					k++;
				}
			}
		}
	}
	for (int i = 0; i < size; i++) {
		y[i] = (i + 1);
	}
	

	double* x = new double[size];
	for (int i = 0; i < size; i++)
	{
		x[i] = { 0 };
	}
	double* p = new double [size];


	int q=0;
	do
	{
		
		for (int i = 0; i < size; i++)
			p[i]=x[i];
		for (int i = 0; i < size; i++)
		{
			double var = 0;
			for (int j = 0; j < i; j++)
				var += (A[i][j] * x[j]);
			for (int j = i + 1; j < size; j++)
				var += (A[i][j] * p[j]);
			x[i] = (y[i] - var) / A[i][i];
		}
		q++;
	} while (!converge(x, p,size));


	//cout << "Korni sistemy: " << endl;
	ofstream otg;
	otg.open("ans2.dat");
	for (int i = 0; i < size; i++)
		otg << x[i] << endl;
	otg.close();
	double l[100];
	double sum;
	cout << "norma nevyzki:" << endl;
	for (int i = 0; i < size; i++)
	{
		sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += A[i][j] * x[j];
		}
		l[i] = abs(y[i] - sum);

	}

	double z = 0;

	for (int i = 0; i < size; i++)
	{
		z += pow(l[i], 2);

	}
	cout << sqrt(z) << endl;
	cout << "Iteracii: " << q << endl;
	return 0;
}
