#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

bool chk(ll n) {
	ll tmp = n;
	ll ret = n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			ret -= ret / i;
		}
	}
	if (n != 1)
		ret -= ret / n;
	return ret * tmp == N;
}

void solve() {
	cin >> N;
	int tmp = N;
	
	int ans = -1;
	for (int x = 1; x <= tmp / x; x++) {
		if (tmp % x == 0) {
			if(chk(x))
				ans = ans > 0 ? min(ans, x) : x;
			if(tmp / x != x && chk(tmp / x))
				ans = ans > 0 ? min(ans, tmp / x) : tmp / x;
		}
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