#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

ll dp[5001], N;
vector<int> arr;

ll re_dp(int cur) {
	if (cur == 0)
		return 1;
	if (dp[cur] != -1)
		return dp[cur];

	ll& ret = dp[cur] = 0;
	for (int prev = cur - 1; prev >= 0; prev--) {
		ll dist = 1ll * (cur - prev) * (1 + abs(arr[cur] - arr[prev]));
		ll res = max(re_dp(prev), dist);
		ret = ret ? min(ret, res) : res;
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

	cout << re_dp(N - 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}