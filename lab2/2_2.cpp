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
double funct3(double x) {
	return (-7+pow(5,x))/6;
}
int main()
{
	double x1, e,h=0;
	e = 0.0001;
	x1 = 1;
	while (abs(x1 - funct3(x1)) > e) {
		x1 = funct3(x1);
		cout << x1 <<" "<< funct3(x1)<< endl;
		h++;
	}
	cout << x1<<" "<<funct1(x1)<<endl;
	cout<<h;
}

