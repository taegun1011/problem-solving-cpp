#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9

vector<vector<int>> graph;
int N;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int BFS(int sr, int sc, int er, int ec, int size) {
	vector<vector<int>> dist(N, vector<int>(N, INF));
	dist[sr][sc] = 0;

	queue<PII> Q;
	Q.push({ sr, sc });
	while (!Q.empty()) {
		auto p = Q.front();
		Q.pop();
		int cr = p.first, cc = p.second;
		if (cr == er && cc == ec)
			return dist[cr][cc];

		for (int i = 0; i < 4; i++) {
			int nr = dir[i][0] + cr;
			int nc = dir[i][1] + cc;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				continue;
			if (graph[nr][nc] > size)
				continue;
			if (dist[nr][nc] > dist[cr][cc] + 1) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	return INF;
}

void solve() {
	cin >> N;

	 graph = vector<vector<int>>(N, vector<int>(N));

	int cr = 0, cc = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 9) {
				cr = i, cc = j;
				graph[i][j] = 0;
			}
		}
	}

	//time
	int size = 2, left = 2, ans = 0;

	while (1) {
		int nr = -1, nc = -1;
		int mn = INF;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] >= 1 && graph[i][j] < size) {
					int dist = BFS(cr, cc, i, j, size);
					if (dist < mn) {
						mn = dist;
						nr = i;
						nc = j;
					}
					else if (dist == mn) {
						PII p1 = { nr, nc }, p2 = { i, j };
						PII temp = p1 < p2 ? p1 : p2;
						nr = temp.first;
						nc = temp.second;
					}
				}
			}
		}

		if (nr < 0)
			break;

		cr = nr;
		cc = nc;
		graph[cr][cc] = 0;
		ans += mn;
		if (!(--left))
			left = ++size;

	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}