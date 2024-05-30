#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

int dp[100001];
int p[100001];
vector<vector<int>> graph;

int re_dp(int cur, int prv) {
	if (dp[cur] != -1)
		return dp[cur];
	int& ret = dp[cur] = 1;
	for (int nxt : graph[cur])
		if (nxt != prv)
			ret += re_dp(nxt, cur);
	return ret;
}

void traverse(int cur, int prv) {
	for (int nxt : graph[cur]) {
		if (nxt != prv) {
			p[nxt] = cur;
			traverse(nxt, cur);
		}
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int R, Q;
	cin >> N >> R >> Q;

	graph = vector<vector<int>>(N + 1, vector<int>());

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	traverse(R, 0);

	while (Q--) {
		cin >> u;
		cout << re_dp(u, p[u]) << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}