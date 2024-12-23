#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long C[31][31]; //C[i][j] = iCj

int factorial(int n) {
	int result = 1;
	for (int i = n; i > 0; i--)
		result *= i;
	return result;
}

int main() {
	//table setup
	int i, j;
	for (i = 1; i <= 30; i++) {
		C[i][1] = i;
		C[i][0] = C[i][i] = 1;
		for (j = 30; j > i; j--)
			C[i][j] = -1;
	}

	for (i = 2; i <= 30; i++) {
		for (j = 2; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}


	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n;
		cin >> m >> n;
		cout << C[n][m] << endl;
	}
}