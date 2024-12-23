#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M = 1000000007;

PII xgcd(int a, int b) {
	if (!b)
		return { 1, 0 };
	auto res = xgcd(b, a % b);
	//ax + by = bz + aw - a/b * bw
	ll tmp = res.first - 1ll * (a / b) * res.second;
	return { res.second, (int)tmp };
}

int mod_inv(int a, int m) {
	auto res = xgcd(a, m);
	if (res.first < 0)
		res.first += M;
	return res.first;
}

int pow(ll a, int b) {
	ll ret = 1;
	while (b) {
		if (b & 1)
			ret = ret * a % M;
		a = a * a % M;
		b >>= 1;
	}
	return (int)ret;
}

void solve() {
	cin >> N;
	int a, b, ans = 0;
	while (N--) {
		cin >> a >> b;
		ans = (1ll * b * mod_inv(a, M) + ans) % M;
		//ans = (1ll * b * pow((ll)a, M - 2) + ans) % M;
	}

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