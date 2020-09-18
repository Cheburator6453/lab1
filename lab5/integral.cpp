#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double funct(double x)
{
	return ((exp(-1/pow(x,2))) / pow(x, 2));
}
int main()
{
	double eps = 0.0001;
	double b = 1.5;
	double a = 8 - log(exp(8)-eps);
	double c = 1000000.0;
	double h = (b - a) / c;
	long double p = 0, p_temp = 0;
	do
	{
		p_temp = p;
		c += 1000000;
		h = (b - a) / c;
		p = 0;
		for (double i = a; i < b; i += h)
		{
			p += h * (funct(i) + funct(i + h)) / 2;

		}
	} while (abs(p - p_temp) > eps);

	cout <<"metod trap: "<<p << " " << abs(p - p_temp)<<endl;


	ofstream out;
	out.open("ans1.dat");
	out << p << " " << abs(p - p_temp)<<endl;
	out.close();


	double eps1 = 0.0001;
	double b1 = 1.5;
	double a1 = 8 - log(exp(8) - eps);
	double c1 = 1000000.0;
	double h1 = (b - a) / c1;
	double p1 = 0, p_temp1 = 0;
	do
	{
		p_temp1 = p1;
		c1 *= 2;
		h1 = (b1 - a1) / c1;
		p1 = 0;
		for (double i = a1; i < b1; i += h1)
		{
			p1 += funct(i) * h1;
		}
	} while (abs(p1 - p_temp1) / 3 > eps1);

	cout << "metod pramoygolnika: " << p1 << " " << abs(p1 - p_temp1) << endl;




	ofstream out1;
	out1.open("ans2.dat");
	out1 << p1 << " " << abs(p1 - p_temp1);
	out1.close();




	return 0;
}
