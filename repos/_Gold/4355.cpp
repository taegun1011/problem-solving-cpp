#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

ll N;

ll phi(ll n) {
	//'n보다 작은' => 1은 예외 처리가 필요, 그 외는 그대로
	if (n == 1)
		return 0;

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
	return ret;
}

void solve() {
	cin >> N;
	while (N) {
		cout << phi(N) << '\n';
		cin >> N;
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