#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define INF 1e12

ll dp[501][501];
vector<int> arr;
vector<int> psum;

ll re_dp(int s, int e) {
	if (s == e)
		return 0;
	if (dp[s][e] != -1)
		return dp[s][e];
	ll& ret = dp[s][e] = INF;
	for (int m = s; m < e; m++)
		ret = min(ret, re_dp(s, m) + re_dp(m + 1, e) + psum[e] - psum[s - 1]);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	arr = vector<int>(N + 1);
	psum = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	cout << re_dp(1, N) << endl;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}