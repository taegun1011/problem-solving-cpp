#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

ll get1(ll x) {
	if (x <= 1)
		return x;

	int expon = 0;
	ll num = 1;
	while (num <= x) {
		num <<= 1;
		expon++;
	}

	ll sum = 0;
	for (int i = 1; i <= expon; i++) {
		sum += (x / (1ll << i)) * (1ll << (i - 1));
		sum += max(x % (1ll << i) - (1ll << (i - 1)) + 1, 0ll);
	}

	return sum;
}

void solve() {
	ll A, B;
	cin >> A >> B;

	cout << get1(B) - get1(A - 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}