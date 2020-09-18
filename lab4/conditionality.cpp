#include <iostream>

using namespace std;

int main()
{
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

	double temp, s, max, max1;
	max = 0;
	max1 = 0;
	double UnitMatrix[100][100];
	double Inverse_Matrix[100][100];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Inverse_Matrix[i][j] = A[i][j];
			UnitMatrix[i][j] = 0.0;
			if (i == j)
				UnitMatrix[i][j] = 1.0;
		}
	}
	//-------------

	for (int k = 0; k < size; k++) {
		temp = Inverse_Matrix[k][k];
		for (int j = 0; j < size; j++) {
			Inverse_Matrix[k][j] /= temp;
			UnitMatrix[k][j] /= temp;
		}
		for (int i = k + 1; i < size; i++) {
			temp = Inverse_Matrix[i][k];
			for (int j = 0; j < size; j++) {
				Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
				UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
			}
		}
	}

	for (int k = size - 1; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--) {
			temp = Inverse_Matrix[i][k];
			for (int j = 0; j < size; j++) {
				Inverse_Matrix[i][j] -= Inverse_Matrix[k][j] * temp;
				UnitMatrix[i][j] -= UnitMatrix[k][j] * temp;
			}
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Inverse_Matrix[i][j] = UnitMatrix[i][j];
			
		}
		
	}

	s = 0;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
			s += A[i][j];
		if (max < s) max = s;
		s = 0;
	}

	s = 0;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
			s += Inverse_Matrix[i][j];
		if (max1 < s) max1 = s;
		s = 0;
	}
	cout <<"Number conditionality: "<< max * max1;


	return 0;
}
