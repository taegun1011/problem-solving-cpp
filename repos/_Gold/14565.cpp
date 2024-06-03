#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

ll N, A;

//ax + by = gcd(a, b)
vector<ll> xgcd(ll a, ll b) {
	if (!b)
		return { a, 1, 0 };

	auto res = xgcd(b, a % b);
	//ax + by = bz + (a - a/b * b)w
	return { res[0], res[2], res[1] - (a / b) * res[2] };
}

ll mod_inv(ll A, ll N) {
	auto res = xgcd(A, N);
	if (res[0] == 1)
		return (res[1] + N) % N;
	return -1;
}

void solve() {
	cin >> N >> A;
	cout << N - A << ' ' << mod_inv(A, N) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}