#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[1001];
vector<vector<int>> graph;

int re_dp(int cur) {
	if (graph[cur].empty())
		return 1;
	if (dp[cur] != -1)
		return dp[cur];

	int& ret = dp[cur];
	for (int nxt : graph[cur])
		ret = max(ret, re_dp(nxt) + 1);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N, M;
	cin >> N >> M;
	graph = vector<vector<int>>(N, vector<int>());

	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < N; i++)
		cout << re_dp(i) << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}