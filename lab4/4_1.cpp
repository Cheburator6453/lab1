#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int size = 100;
double* methodGauss(double** a, double* y, int size) {
	double* x;
	x = new double[size];
	int k = 0;
	int index;
	double eps = 0.0001;
	double max;
	while (k < size)
	{

		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < size; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}

		if (max < eps)
		{
			return 0;
		}
		for (int j = 0; j < size; j++)
		{
			double temp = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = temp;
		}
		double temp = y[k];
		y[k] = y[index];
		y[index] = temp;

		for (int i = k; i < size; i++)
		{
			double temp = a[i][k];
			if (abs(temp) < eps) continue;
			for (int j = 0; j < size; j++)
				a[i][j] = a[i][j] / temp;
			y[i] = y[i] / temp;
			if (i == k) continue;
			for (int j = 0; j < size; j++)
				a[i][j] = a[i][j] - a[k][j];
			y[i] = y[i] - y[k];
		}
		k++;
	}

	for (k = size - 1; k >= 0; k--)
	{
		x[k] = y[k];
		for (int i = 0; i < k; i++)
			y[i] = y[i] - a[i][k] * x[k];
	}
	return x;
}

int main() {
	double** A, * y;
	int size=100;
	//cout << "Enter size(100)"<<endl;
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
	int n = 100, i, j, k;
	double d, s;
	for (k = 0; k < n; k++)
	{
		for (j = k + 1; j < n; j++)
		{
			d = A[j][k] / A[k][k];
			for (i = k; i < n; i++)
			{
				A[j][i] = A[j][i] - d * A[k][i];
			}
			y[j] = y[j] - d * y[k];
		}
	}
	for (k = n - 1; k >= 0; k--)
	{
		d = 0;
		for (j = k + 1; j < n; j++)
		{
			s = A[k][j] * x[j];
			d = d + s;
		}
		x[k] = (y[k] - d) / A[k][k];
	}
	ofstream otg;
	otg.open("ans1.dat");
	//cout << "Korni sistemy: " << endl;
	for (i = 0; i < n; i++)
		otg <<  x[i]  << endl;
	otg.close();
	double l[100];
	double sum;
	cout<<"norma nevyzki:"<<endl;
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
	
	return 0;
}
