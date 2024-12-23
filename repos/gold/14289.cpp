#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int mod = 1e9 + 7;

int N;

vector<vector<int>> idMatrix() {
	vector<vector<int>> ret(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		ret[i][i] = 1;
	return ret;
}

vector<vector<int>> mul(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> res(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				res[i][j] += (1ll * A[i][k] * B[k][j]) % mod;
				res[i][j] %= mod;
			}
		}
	}

	return res;
}

//Çà·Ä Á¦°ö
vector<vector<int>> pow(vector<vector<int>> w, int m) {
	if (!m)
		return idMatrix();

	if (m & 1)
		return mul(pow(w, m - 1), w);
	vector<vector<int>> half = pow(w, m / 2);
	return mul(half, half);
}

void solve() {

	int M;
	cin >> N >> M;
	vector<vector<int>> w(N, vector<int> (N));

	int u, v;
	while (M--) {
		cin >> u >> v;
		w[u-1][v-1] = w[v-1][u-1] = 1;
	}

	int D;
	cin >> D;
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