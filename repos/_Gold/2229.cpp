#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> arr;

int dp[1001];
int N;

int re_dp(int cur) {
	if (cur == N)
		return 0;

	if (dp[cur] != -1)
		return dp[cur];

	int& ret = dp[cur];
	int mx = arr[cur], mn = arr[cur];
	for (int nxt = cur + 1; nxt < N; nxt++) {
		ret = max(ret, mx - mn + re_dp(nxt));
		mx = max(mx, arr[nxt]);
		mn = min(mn, arr[nxt]);
	}
	ret = max(ret, mx - mn);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

	cout << re_dp(0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}