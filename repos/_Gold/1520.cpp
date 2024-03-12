#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M;
int dp[501][501];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int re_dp(int cr, int cc, vector<vector<int>>& map) {
	if (!cr && !cc)
		return 1;
	if (dp[cr][cc] != -1)
		return dp[cr][cc];
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0];
		int nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;
		if (map[nr][nc] > map[cr][cc])
			ret += re_dp(nr, nc, map);
	}
	return dp[cr][cc] = ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M));

	for (auto& row : map)
		for (int& cell : row)
			cin >> cell;
	cout << re_dp(N - 1, M - 1, map) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}