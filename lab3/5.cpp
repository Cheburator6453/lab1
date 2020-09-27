#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#define STRS 183

using namespace std;

void   inversion(double** A, int N);
void   print(double** temp, int n, int k);
double Steppolinom(double x, int s, double** koef);
void   multiply(double** A, double** B, double** C, int c, int d, int f);

int main() {

	double inp; // vvod
	string line;
	int j;

	double** temp = new double*[STRS];
	for (int i = 0; i < STRS; i++)  temp[i] = new double[13];
	for (int i = 0; i < STRS; i++) for (int j = 0; j < 13; j++) temp[i][j] = 0;
	int n = 0;
	ifstream file;
	file.open("16_.csv");

	if (!file.is_open()) {
		cout << "Unknown Error \n";
	}

	while (file.good()) {
		getline(file, line);
		if (n != 0) {
			for (long long unsigned int i = 0; i < line.size(); i++) {
				if (line[i] == ',') line[i] = ' ';
			};
			stringstream ss(line);
			j = 0;
			while ((ss >> inp) && j < 13) {
				temp[n - 1][j] = inp;
				j++;
			}
		}
		n++;
	}
	n = STRS;
	ofstream file2;
	file2.open("laba5.txt");

	int s = 3;
	int month = 7;

	vector<double>  temperature;
	vector<int> stroki;
	int nstrok = 0;

	for (int i = 0; i < STRS; i++) {
		if (temp[i][month] != 999.9) {
			temperature.push_back(temp[i][month]);
			nstrok++;
			stroki.push_back(nstrok);
		}
	}

	cout << "Amount of right degrees: " << temperature.size() << endl;

	int n1 = stroki.size();
	double** firstmat = new double*[s + 1];
	double** secondmat = new double*[s + 1];

	for (int i = 0; i < s + 1; i++) {
		secondmat[i] = new double[1];
	}

	for (int i = 0; i < s + 1; i++) {
		secondmat[i][0] = 0;
	}

	for (int i = 0; i < s + 1; i++) {
		for (int j = 0; j < n1; j++) {
			secondmat[i][0] += temperature[j] * pow(stroki[j], i);
		}
	}

	for (int i = 0; i < s + 1; i++) {
		firstmat[i] = new double[s + 1];
	}

	for (int i = 0; i < s + 1; i++) {
		for (int j = 0; j < s + 1; j++) {
			if (i == 0 && j == 0) {
				firstmat[i][j] = n1;
			}
			else {
				firstmat[i][j] = 0;
				for (int k = 0; k < n1; k++) {
					firstmat[i][j] += pow(stroki[k], i + j);
				}
			}
		}
	}


	double** koef = new double*[s + 1];
	for (int i = 0; i < s + 1; i++) {
		koef[i] = new double[1];
	}

	for (int i = 0; i < s + 1; i++) {
		koef[i][0] = 0.0;
	}

	inversion(firstmat, s + 1);


	multiply(firstmat, secondmat, koef, s + 1, s + 1, 1);
	cout << "Matryx koef: " << endl;
	print(koef, s + 1, 1);
	cout << endl;

	int k = stroki[n1 - 1];
	for (double i = 0; i < k; i += 0.1) {
		file2 << i << "\t  " << Steppolinom(i, s, koef) << endl;
	}
	file2.close();

	print(temp, STRS, 12);
	delete[] temp;

	system("python3 5.py");
	system("pause");
	return 0;
}


void print(double** temp, int n, int k) {
	for (int i = 0; i < n; i++) {
		cout << i << "\t ";
		for (int j = 0; j < k; j++) {
			cout << temp[i][j] << "\t ";
		}
		cout << endl;
	}
}


double Steppolinom(double x, int s, double** koef) {
	double y = 0.0;
	for (int i = 0; i <= s; i++) {
		y += koef[i][0] * pow(x, i);
	}

	return y;
}


void inversion(double** A, int N)
{
	double temp;

	double** E = new double*[N];

	for (int i = 0; i < N; i++) {
		E[i] = new double[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			E[i][j] = 0.0;

			if (i == j) {
				E[i][j] = 1.0;
			}
		}
	}

	for (int k = 0; k < N; k++) {
		temp = A[k][k];

		for (int j = 0; j < N; j++) {
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++) {
			temp = A[i][k];

			for (int j = 0; j < N; j++) {
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--) {
			temp = A[i][k];

			for (int j = 0; j < N; j++) {
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = E[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		delete[] E[i];
	}

	delete[] E;

}


void multiply(double** A, double** B, double** C, int c, int d, int f) {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < f; j++) {
			for (int r = 0; r < d; r++) {
				C[i][j] += A[i][r] * B[r][j];
			}
		}
	}
}
