#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int mod = 1000000007;
int N, M;

ll pow(ll a, ll m) {
	ll ret = 1;
	while (m) {
		if (m & 1)
			ret = ret * a % mod;
		a = a * a % mod;
		m >>= 1;
	}

	return ret;
}

pair<ll, ll> mod_inv(ll a, ll b) {
	if (!b)
		return { 1, 0 };
	auto res = mod_inv(b, a % b);
	return { res.second, res.first - (a / b) * res.second };
}

//1 + r + ... + r^n까지의 합
int geometric_sum(ll r, ll n) {
	ll x = (pow(r, n + 1) - 1 + mod) % mod;
	ll y = mod_inv(r - 1, mod).first;
	if (y < 0) y += mod;

	return (int)(x * y % mod);
}

void solve() {
	cin >> N >> M;

	vector<PII> factors;
	int sqrtn = sqrt(N);
	for (int i = 2; i <= sqrtn; i++) {
		int expon = 0;
		if (N % i == 0) {
			while (N % i == 0) {
				expon++;
				N /= i;
			}
			factors.push_back({ i, expon });
		}
	}
	if (N != 1)
		factors.push_back({ N, 1 });

	ll ans = 1;
	for (auto f : factors)
		ans = (ans * geometric_sum(f.first, 1ll * f.second * M)) % mod;

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