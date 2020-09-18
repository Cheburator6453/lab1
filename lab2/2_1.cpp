
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double funct1(double x) {
	return pow(5,x)-6*x-7;
}
double funct2(double x) {
	return pow(5,x)*log(5)-6;
}
int main()
{
	ofstream out;
	out.open("abc.txt");
	double e, x, xn,h;
	e = 0.0001;
	x = funct1(1);
	xn = x - funct1(x) / funct2(x);
	while (abs(xn - x) > e) {
		x = xn;
		xn = x - funct1(x) / funct2(x);
        h++;
	}
	for (int i = -20; i <=20; i +=1) {
		out << i << " " << funct1(i) << endl;
	}
        cout << xn << endl;
	cout << funct1(xn)<<endl;
	cout<<h;

system("python3 abc.py");



}
