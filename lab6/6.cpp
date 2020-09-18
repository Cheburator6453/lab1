#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

double func(double x1, double x2)
{
	return -(-x1 * x1 - 13 * x1 - x2 * x2 - 4 * x2 - 37);
}

double dfunc_x1(double x1) {
	return (2 * x1 + 13);
}

double dfunc_x2(double x2) {
	return (2 * x2 + 4);
}

int i;
double norm(double x1, double x2) {
	i++;
	return  sqrt(dfunc_x1(x1) * dfunc_x1(x1) + dfunc_x2(x2) * dfunc_x2(x2));
}

vector<double> intervalunimod(double x0, double y0) {
	    vector<double> interval;
		double h = 1;
		double x1 = 0;
		double x2 = x1 + h;
		double alph0 = 0;
		double f1, f2;
		f1 = func(x0 + alph0 * dfunc_x1(x0), y0 + alph0 * dfunc_x2(y0));
		f2 = func(x0 + (alph0 - h) * dfunc_x1(x0), y0 + (alph0 - h) * dfunc_x2(y0));
		if (f2 > f1)
		{
			h = -h;
			x2 = x1 + h;
		}
		while (f2 < f1)
		{
			x1 = x2;
			x2 = x1 + h;
			h = h * 2;
		}
		interval.push_back(x2 - h);
		interval.push_back(x2 + h);
		return interval;

	
}

double alpha_by_kv_interpolate(double x0, double y0) {
	vector<double> interval = intervalunimod(x0, y0);
	double x1;
	double x2;
	double x3;
	double x_;
	double xmin;
	double xm;
	double e = 0.001;
	x1 = (interval[0] + interval[1]) / 2;
	double h = 0.1;
	do {
		x2 = x1 + h;
		if (func(x0 + x1 * dfunc_x1(x0), y0 + x1 * dfunc_x2(y0)) > func(x0 + x2 * dfunc_x1(x0), y0 + x1 * dfunc_x2(y0))) x3 = x1 + 2 * h;
		else x3 = x1 - h;
		double f1, f2, f3;
		f1 = func(x0 + x1 * dfunc_x1(x0), y0 + x1 * dfunc_x2(y0));
		f2 = func(x0 + x2 * dfunc_x1(x0), y0 + x2 * dfunc_x2(y0));
		f3 = func(x0 + x2 * dfunc_x1(x0), y0 + x2 * dfunc_x2(y0));
		x_ = ((x2 * x2 - x3 * x3) * f1 + (x3 * x3 - x1 * x1) * f2 + (x1 * x1 - x2 * x2) * f3) / (2 * ((x2 - x3) * f1 + (x3 - x1) * f2 + (x1 - x2) * f3));
		if (f1 < f2 && f1 < f3) xmin = f1;
		if (f2 < f1 && f2 < f3) xmin = f2;
		else xmin = f3;
		if (((x2 - x3) * f1 + (x3 - x1) * f2 + (x1 - x2) * f3) == 0) {
			x1 = xmin;
			continue;
		}
		if (x_ <= x3 && x_ >= x1) x1 = func(x0 + xmin * dfunc_x1(x0), y0 + xmin * dfunc_x2(y0)) > func(x0 + x_ * dfunc_x1(x0), y0 + x_ * dfunc_x2(y0)) ? func(x0 + x_ * dfunc_x1(x0), y0 + x_ * dfunc_x2(y0)) : func(x0 + xmin * dfunc_x1(x0), y0 + xmin * dfunc_x2(y0));
		else x1 = x_;
	} while (abs(xmin - x_) > e);
	return x_;
}

vector<double> find(double x1, double x2, double b = 0.001) {
	double x01 = x1;
	double  x02 = x2;
	double normgrad = norm(x01, x02);
	double H1 = dfunc_x1(x01);
	double H2 = dfunc_x2(x02);
	ofstream file("data.txt");
	while (normgrad > b) {
		//cout << x01 << " " << x02 << endl;
		file << x01 << " " << x02 << endl;
		x01 -=  0.001* H1;
		x02 -=  0.001* H2;
		normgrad = norm(x01, x02);
		H1 = dfunc_x1(x01);
		H2 = dfunc_x2(x02);
	}
	vector<double> result;
	result.push_back(x01);
	result.push_back(x02);
	return result;
}
int main()
{
	vector<double> result = find(9, 10);
	cout << result[0] << " " << result[1] << endl;
        cout << "iter: " << i << endl;
}
