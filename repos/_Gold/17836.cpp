#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M, T;

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void solve() {
	cin >> N >> M >> T;

	vector<vector<int>> graph(N, vector<int>(M));
	vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, INF)));

	for (auto& row : graph)
		for (int& x : row)
			cin >> x;
	
	//R, C, flag
	queue<vector<int>> Q;
	Q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur[0], cc = cur[1], cf = cur[2];
		if (cr + 1 == N && cc + 1 == M)
			continue;

		for (int i = 0; i < 4; i++) {
			int nr = dir[i][0] + cr, nc = dir[i][1] + cc, nf = cf;

			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if (graph[nr][nc] == 1 && !cf)
				continue;
			if (graph[nr][nc] == 2)
				nf = 1;
			if (dist[nr][nc][nf] > dist[cr][cc][cf] + 1) {
				dist[nr][nc][nf] = dist[cr][cc][cf] + 1;
				Q.push({ nr, nc, nf });
			}
		}
	}

	int ans = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
	cout << (ans <= T ? to_string(ans) : "Fail") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}