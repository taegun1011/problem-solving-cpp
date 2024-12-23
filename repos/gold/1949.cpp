#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[10001][2];

vector<vector<int>> graph;
vector<int> arr;

//prv : 사이클 방지
int re_dp(int cur, int prv, int chosen) {
	int& ret = dp[cur][chosen];

	if (ret != -1)
		return ret;

	ret = chosen * arr[cur];
	for (int nxt : graph[cur]) {
		if (nxt == prv)
			continue;

		if (chosen)
			ret += re_dp(nxt, cur, 0);
		else
			ret += max(re_dp(nxt, cur, 1), re_dp(nxt, cur, 0));
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;
	graph = vector<vector<int>>(N, vector<int>());

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	cout << max(re_dp(0, -1, 0), re_dp(0, -1, 1)) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}