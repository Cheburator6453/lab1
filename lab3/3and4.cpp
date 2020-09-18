#include<iostream>
#include<vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int fact(int n) {
	if (n == 1 || n == 0)
		return 1;
	return n * fact(n - 1);
}
double raznx1(double x, vector<double> xl, int i) {
	double rez1 = 1;
	if (i == 0) return 1;
	for (int j = 0; j < i; j++) {
		rez1 *= (x - xl[j]);

	}
	return rez1;
}
double d(vector<double> y, int n, int i) {
	if (n == 0) return y[i];
	return d(y, n - 1, i + 1) - d(y, n - 1, i);
}

double raznx2(double x, vector<double>xl, int i) {
	double rez2 = 1;
	if (i == 0) return 1;
	reverse(xl.begin(), xl.end());
	for (int j = 0; j < i; j++) {
		rez2 *= (x - xl[j]);
	}
	return rez2;
}
int main() {
	string str, word;
	ifstream In("16.csv");
	vector<vector<double> >b;
	vector<double> c;
	double number;
	getline(In, str);
	while (!In.eof())
	{
		getline(In, str);
		stringstream s(str);
		while (getline(s, word, ',')) {
			number = atof(word.c_str());
			c.push_back(number);
			if (c.size() == 14) {
				b.push_back(c);
				c.clear();
				continue;
			}
		}
	}
	vector<double>xl2, yl2;
	for (int i = 85; i < 91; i++) {
		yl2.push_back(b[i][6]);
	}
	for (int i = 0; i < 6; i++) {
		xl2.push_back(i);
	}
	for (int i = 0; i < yl2.size(); i++) {
		cout << yl2[i] << endl;
	}

	ofstream file1, file2;
	file1.open("laba3.txt");
	file2.open("laba4.txt");
	double temp = 0;
	for (double i = 0; i < xl2.size(); i += 0.1) {
		for (int j = 0; j < 6; j++) {
			temp += d(yl2, j, 0) * raznx1(i, xl2, j) / fact(j);

		}
		file1 << i << " " << temp << endl;
		temp = 0;
	}
	for (double i = 0; i < xl2.size(); i += 0.1) {
		for (int k = 0; k < 6; k++) {
			temp += d(yl2, k, yl2.size() - k - 1) * raznx2(i, xl2, k) / fact(k);

		}
		file2 << i << " " << temp << endl;
		temp = 0;
	}


}

