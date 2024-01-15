#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void solve() {
	int w, h;
	cin >> w >> h;
	vector<string> graph(h);
	vector<vector<int>> dist(h, vector<int>(w));

	queue<pair<int, int>> Q;
	
	for (int i = 0; i < h; i++)
		cin >> graph[i];

	int sc, sr;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (graph[i][j] == '*')
				Q.push({ i,j });
			else if (graph[i][j] == '@')
				sr = i, sc = j;
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

			if ((graph[nr][nc] == '.' || graph[nr][nc] == '@') && !dist[nr][nc]) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr,nc });
			}
		}
	}

	queue<tuple<int, int, int>> newQ;
	
	vector<vector<bool>> visited(h, vector<bool>(w));
	
	visited[sr][sc] = 1;
	newQ.push({ sr,sc,0 });

	while (!newQ.empty()) {
		auto cur = newQ.front();
		newQ.pop();

		int cr = get<0>(cur), cc = get<1>(cur), cd = get<2>(cur);
		if (cr == 0 || cr == h - 1 || cc == 0 || cc == w - 1) {
			cout << cd + 1 << endl;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1], nd = cd + 1;
			if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

			if ((graph[nr][nc] == '.') && !visited[nr][nc] && (!dist[nr][nc] || nd < dist[nr][nc])) {
				visited[nr][nc] = 1;
				newQ.push({ nr,nc,nd });
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;
}

int main() {
	FASTIO;
	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}