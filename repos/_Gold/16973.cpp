#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void solve() {
	cin >> N >> M;
	vector<vector<int>> graph(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> graph[i][j];

	int h, w, sr, sc, fr, fc;
	cin >> h >> w >> sr >> sc >> fr >> fc;
	
	vector<vector<int>> dist(N + 1, vector<int>(M + 1, INF));
	dist[sr][sc] = 0;

	queue<PII> Q;
	Q.push({ sr, sc });

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		if (cr == fr && cc == fc)
			break;

		for (int i = 0; i < 4; i++) {
			int nr = dir[i][0] + cr, nc = dir[i][1] + cc;

			if (nr <= 0 || nr + h > N + 1 || nc <= 0 || nc + w > M + 1)
				continue;

			//변 4방향 확인
			bool flag = true;

			for (int r = nr; r < nr + h; r++)
				if (graph[r][nc] || graph[r][nc + w - 1]) {
					flag = false;
					break;
				}
			for (int c = nc; c < nc + w; c++)
				if (graph[nr][c] || graph[nr + h - 1][c]) {
					flag = false;
					break;
				}

			if (!flag) continue;
			if (dist[nr][nc] > dist[cr][cc] + 1) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	cout << (dist[fr][fc] == INF ? -1 : dist[fr][fc]) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}