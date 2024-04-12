#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9

int dp[5001], N, K;
vector<int> arr;

int re_dp(int cur) {
	if (cur == 0)
		return 1;
	if (dp[cur] != -1)
		return dp[cur];

	int& ret = dp[cur] = 0;
	for (int prev = cur - 1; prev >= 0; prev--) {
		int dist = (cur - prev) * (1 + abs(arr[cur] - arr[prev]));
		if (dist <= K)
			ret |= re_dp(prev);
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> K;

	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

	cout << (re_dp(N - 1) ? "YES" : "NO") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}