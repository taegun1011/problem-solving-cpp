#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define MATRIX vector<vector<ll>>
#define MOD 1000003

int N;
MATRIX id_matrix() {
	MATRIX ret(N * 5, vector<ll>(N * 5));
	for (int i = 0; i < ret.size(); i++)
		ret[i][i] = 1;
	return ret;
}

MATRIX mul(MATRIX& A, MATRIX& B) {
	MATRIX C(N * 5, vector<ll>(N * 5));

	for (int i = 0; i < N * 5; i++)
		for (int j = 0; j < N * 5; j++)
			for (int k = 0; k < N * 5; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

	return C;
}

MATRIX pow(MATRIX A, int T) {
	MATRIX ret = id_matrix();

	while (T > 0) {
		if (T & 1)
			ret = mul(ret, A);
		A = mul(A, A);
		T >>= 1;
	}

	return ret;
}

void solve() {
	int S, E, T;
	cin >> N >> S >> E >> T;

	MATRIX m(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			m[i][j] = ch - '0';
		}
	}

	//점화식으로 구성한 행렬
	MATRIX A(N * 5, vector<ll>(N * 5));
	for (int i = 0; i < N * 5; i++) {
		if (i % 5 == 0)
			continue;
		A[i][i - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j])
				A[j * 5][i * 5 + m[i][j] - 1] = 1;
		}
	}

	//5까지는 직접 계산?
	//B[i][j] : i번 점에 j분만에 도착하는 경로의 개수
	MATRIX B(N, vector<ll>(5));
	B[S - 1][0] = 1;

	for (int k = 1; k < 5; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (m[i][j] && k >= m[i][j])
					B[j][k] += B[i][k - m[i][j]];
	
	//B를 이용해 계산한 너비 1의 행렬
	vector<ll> C(N * 5);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			C[i * 5 + j] = B[i][4 - j];
		}
	}

	MATRIX res = pow(A, T - 4);
	ll ans = 0;
	for (int i = 0; i < N * 5; i++)
		ans = (ans + res[(E - 1) * 5][i] * C[i]) % MOD;

	//길이가 5 이하면 따로 처리해야하나..?
	if (T < 5)
		ans = C[(E - 1) * 5 + 4 - T];

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}