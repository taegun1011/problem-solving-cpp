#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int mod = 1e9 + 7;

vector<vector<int>> idMatrix() {
	vector<vector<int>> ret(8,vector<int> (8));
	for (int i = 0; i < 8; i++)
		ret[i][i] = 1;
	return ret;
}

vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> res(8, vector<int>(8));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				res[i][j] += (1ll * A[i][k] * B[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
	}

	return res;
}

//Çà·Ä Á¦°ö
vector<vector<int>> pow(vector<vector<int>> w, int N) {
	if (!N)
		return idMatrix();

	if (N & 1)
		return mul(pow(w, N-1), w);
	vector<vector<int>> half = pow(w, N / 2);
	return mul(half, half);
}

void solve() {

	int D;
	cin >> D;

	vector<vector<int>> w = {
		{0,1,1,0,0,0,0,0},
		{1,0,1,1,0,0,0,0},
		{1,1,0,1,1,0,0,0},
		{0,1,1,0,1,1,0,0},
		{0,0,1,1,0,1,1,0},
		{0,0,0,1,1,0,0,1},
		{0,0,0,0,1,0,0,1},
		{0,0,0,0,0,1,1,0}
	};

	vector<vector<int>> wd = pow(w, D);

	cout << wd[0][0] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}