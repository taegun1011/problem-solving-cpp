#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

ll N, K;

bool chk(ll m) {
	return (m + 1) * (N - m + 1) >= K;
}

void solve() {
	cin >> N >> K;
	ll s = 0, e = N / 2, m;

	//NNNNYYYYY
	while (s < e) {
		m = s + (e - s) / 2;
		if (chk(m))
			e = m;
		else
			s = m + 1;
	}

	cout << ((s + 1) * (N - s + 1) == K ? "YES" : "NO") << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}