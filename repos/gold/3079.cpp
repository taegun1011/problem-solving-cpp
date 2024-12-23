#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

vector<int> arr;
ll N, M;

bool check(ll k) {
	ll sum = 0;
	for (ll x : arr)
		sum += k / x;
	
	return sum >= M;
}

void solve() {
	cin >> N >> M;

	arr = vector<int> (N);
	for (int& x : arr)
		cin >> x;

	ll s = 1, e = 1e18, m;

	//NNNNNYYYYY
	while (s < e) {
		m = (s + e) / 2;
		if (check(m))
			e = m;
		else
			s = m + 1;
	}

	cout << s << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}