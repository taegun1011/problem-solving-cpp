#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
	cin >> N >> M;
	vector<int> arr(N + 1);
	vector<ll> psum(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	vector<int> remainder(M);
	for (int i = 1; i <= N; i++)
		remainder[psum[i] % M]++;

	ll ans = remainder[0];
	for (int& r : remainder)
		ans += (-1ll + r) * r / 2;

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}