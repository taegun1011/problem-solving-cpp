#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> graph;

int dp[301][301];
int N;

int re_dp(int cur, int left) {
	if (left == 0 && cur != N)
		return INT_MIN;

	if (cur == N)
		return 0;

	if (dp[cur][left] != -1)
		return dp[cur][left];

	int& ret = dp[cur][left] = INT_MIN;
	for (int nxt = cur + 1; nxt <= N; nxt++)
		if(graph[cur][nxt])
			ret = max(ret, re_dp(nxt, left - 1) + graph[cur][nxt]);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int M, K;
	cin >> N >> M >> K;
	graph = vector<vector<int>> (N + 1, vector<int>(N + 1));
	while (K--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = max(graph[a][b], c);
	}

	int ans = re_dp(1, M - 1);
	cout << (ans < 0 ? 0 : ans) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}