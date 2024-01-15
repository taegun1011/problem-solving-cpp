#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define matrix vector<vector<ll>>
#include <iostream>
#include <vector>
using namespace std;

matrix fibonacci(ll n);
matrix multiply(matrix, matrix);

int main() {
	ll n;
	cin >> n;

	matrix result = fibonacci(n);
	cout << result[0][0] << endl;
}

matrix multiply(matrix a, matrix b) {
	int size = a[0].size();
	if (size != b.size()) return matrix(0);

	int row = a.size(), col = b[0].size();

	int i, j, k;
	ll sum;
	matrix res(row, vector<ll> (col));

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			sum = 0;
			for (k = 0; k < size; k++) {
				sum += (a[i][k] * b[k][j]);
				sum %= 1000000007;
			}
			res[i][j] = sum;
		}
	}

	return res;
}

matrix fibonacci(ll n) {
	matrix base = { {1,1},{1,0} };
	matrix result = { {1,0},{0,1} };

	n--;
	while (n > 0) {
		if (n % 2) {
			result = multiply(result, base);
		}
		base = multiply(base, base);
		n /= 2;
	}

	return result;
}