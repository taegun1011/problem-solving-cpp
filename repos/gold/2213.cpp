#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> graph;
vector<int> W;

int dp[10005][2];
bool visited[10005];
vector<int> ans;

int re_dp(int cur, int prv, int used) {
	if (dp[cur][used] != -1)
		return dp[cur][used];
	int& ret = dp[cur][used] = W[cur] * used;
	for (int nxt : graph[cur]) {
		if (nxt == prv)
			continue;
		if (used)
			ret += re_dp(nxt, cur, 0);
		
		else
			ret += max(re_dp(nxt, cur, 0), re_dp(nxt, cur, 1));
	}

	return ret;
}

void find_path(int cur, int prv) {
	//cur번 원소가 선택되는 경우 = re_dp에서 used = 0이고 re_dp(nxt, cur, 1)이 더 컸을 경우
	if (dp[cur][1] > dp[cur][0] && !visited[prv])
		visited[cur] = true;

	for (int nxt : graph[cur]) {
		if (nxt == prv)
			continue;
		find_path(nxt, cur);
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	graph = vector<vector<int>>(N + 1, vector<int>());
	W = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> W[i];

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	graph[0].push_back(1);

	int result = re_dp(0, -1, 0);
	cout << result << endl;

	find_path(0, -1);

	for (int i = 1; i <= N; i++)
		if (visited[i])
			cout << i << ' ';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}