#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

vector<ll> mod_inv(ll a, ll b) {
	if (!b)
		return { a, 1, 0 };
	auto res = mod_inv(b, a % b);
	return { res[0], res[2], res[1] - (a / b) * res[2] };
}

void solve() {
	cin >> N >> M;
	if (M == 1)
		cout << (N == 1e9 ? "IMPOSSIBLE" : to_string(N + 1)) << endl;
	//N^-1 (mod M)
	else {
		auto res = mod_inv(M, N);
		if (res[1] <= 0) res[1] += N;
		cout << ((res[0] != 1 || res[1] > 1e9) ? "IMPOSSIBLE" : to_string(res[1])) << endl;
	}
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}