#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

void solve() {
	int N, K;
	cin >> N >> K;

	vector<ll> arr(N + 1), psum(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	ll ans = 0;
	map<ll, ll> M;
	for (int i = 1; i <= N; i++) {
		if (psum[i] == K) ans++;
		ans += M[psum[i] - K];
		M[psum[i]]++;
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