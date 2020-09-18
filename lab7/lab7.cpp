#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
const double eps = 0.01;

void Shema(double* y, double* y1, double h) {
	int N = int(2 / h) + 1;
	double* yy = new double[2];
	for (int i = 1; i < N; i++) {
		yy[0] = y[i - 1] + h * y1[i - 1];
		yy[1] = y1[i - 1] + h * (-1.25 * y1[i - 1] - 0.5 * y[i - 1] + 0.25 * (i - 1) * h * exp(-h * (i - 1)));
		y[i] = h * 0 + y[i - 1] - h * (0 * yy[0] - 1 * yy[1]);
		y1[i] = h * (0.25 * (i - 1) * h * exp(-(i - 1) * h)) + y1[i - 1] - h * (0.5 * yy[0] + 1.25 * yy[1]);
	}
}

int main() {
	double h = 0.5;
	int N = int(2 / h) + 1;
	ofstream sh;
	sh.open("Shema.txt");
	ofstream resh;
	resh.open("ToResh.txt");
	double R1;
	do {
		double* a = new double[N];
		double* y = new double[N];
		double* y1 = new double[N];
		y[0] = 1;
		y1[0] = 0;
		Shema(y, y1, h);
		for (int i = 0; i < N; i++) a[i] = y[i];
		h /= 2.; N = int(2 / h) + 1;
		double* b = new double[N];
		double* y2 = new double[N];
		double* y3 = new double[N];
		y2[0] = 1;
		y3[0] = 0;
		Shema(y2, y3, h);
		for (int i = 0; i < N; i += 2) b[i] = y2[i];
		R1 = 0;
		int K = 0;
		for (int i = 0; i < N; i += 2) {
			double R2;
			R2 = fabs(a[K] - b[i]);
			K++;
			if (R2 > R1) R1 = R2;
		}
		if (R1 <= eps) {
			for (int i = 0; i < N; i++) {
				sh << h * i << " " << y2[i] << " " << y3[i] << endl;
				cout << y2[i] << endl;
			}
		}

	} while (R1 > eps);
	cout << endl;
	for (double x = 0.; x <= 2; x += 0.01) {
		double Y;
		Y = (x + 3) * exp(-x) + ((6 * sqrt(7) * sin(sqrt(7) * x / 8.)) / 7. - 2 * cos(sqrt(7) * x / 8.)) / pow(exp(x), 5. / 8.);
		resh << x << " " << Y << endl;
		
	}
	
	return 0;
}


