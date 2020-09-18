#include <iostream>
#include <cmath>
using namespace std;
double funct(double x) {
	return x*x*x*x-18*x*x+5*x-8;
}
int main()
{
	double a, b;
	a = -3;
	b = -2;
	double c;
	c = (a + b) / 2;
        int h=0;
        while (funct(a)*funct(b)>0){
        a++;
        b++;
        }
        cout<<a<<endl;
        cout<<b<<endl;
        double e = 0.001;
	while (abs(funct(c)) > e) {
                h++;
		if (funct(c) * funct(a) < 0) {
			b = c;
		}
		if (funct(c) * funct(a) > 0) {
			a = c;
		}
                c = (a + b) / 2;
	}
	cout << "koren="<<c<<endl;
	cout<<"itera="<<h<<endl;
	cout << funct(c);
	
}



