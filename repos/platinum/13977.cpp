#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define MOD 1000000007ll

ll fact[4000001];

ll pow(ll A, ll B) {
	ll mul = 1;
	while (B) {
		if (B & 1)
			mul = (mul * A) % MOD;
		A = (A * A) % MOD;
		B >>= 1;
	}

	return mul;
}

ll comb(int N, int K) {
	ll KNK = fact[K] * fact[N - K] % MOD;
	return fact[N] * pow(KNK, MOD - 2) % MOD;
}

void solve() {
	fact[0] = 1;

	for (int i = 1; i <= 4000000; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	int M;
	cin >> M;

	while (M--) {
		int N, K;
		cin >> N >> K;

		cout << comb(N, K) << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}