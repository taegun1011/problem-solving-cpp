#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD	1000003l

int N;
vector<vector<int>> idmatrix() {
	vector<vector<int>> ret(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		ret[i][i] = 1;
	return ret;
}

vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
	vector<vector<int>> c(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				c[i][j] = (int)((0l + c[i][j] + a[i][k] * b[k][j]) % MOD);

	return c;
}

vector<vector<int>> pow(vector<vector<int>>& matrix, int T) {
	vector<vector<int>> ret = idmatrix();

	while (T) {
		if (T % 2)
			ret = mul(ret, matrix);
		matrix = mul(matrix, matrix);
		T >>= 1;
	}

	return ret;
}

void solve() {
	int S, E, T;
	cin >> N >> S >> E >> T;

	vector<vector<int>> matrix(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			matrix[i][j] = ch - '0';
		}
	}

	cout << pow(matrix, T)[S - 1][E - 1] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}