#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int L, R, C;
short dir[6][3] = { 0,0,1,0,0,-1,0,1,0,0,-1,0,-1,0,0,1,0,0 };

void BFS(vector<vector<string>>& graph, int sl, int sr, int sc, int el, int er, int ec) {
	queue<tuple<int, int, int>> Q;
	int dist[31][31][31] = { 0, };

	Q.push({ sl,sr,sc });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cl = get<0>(cur), cr = get<1>(cur), cc = get<2>(cur);

		for (int i = 0; i < 6; i++) {
			int nl = cl + dir[i][0], nr = cr + dir[i][1], nc = cc + dir[i][2];
			if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			if (graph[nl][nr][nc] == '.' && !dist[nl][nr][nc]) {
				dist[nl][nr][nc] = dist[cl][cr][cc] + 1;
				Q.push({ nl,nr,nc });
			}

			if (graph[nl][nr][nc] == 'E') {
				cout << "Escaped in " << dist[cl][cr][cc] + 1 << " minute(s).\n";
				return;
			}
		}
	}

	cout << "Trapped!\n";
}

int main() {
	FASTIO;

	cin >> L >> R >> C;
	while (L) {
		vector<vector<string>> graph(L, vector<string>(R));
		string temp;

		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
				cin >> graph[i][j];

		int sl, sr, sc, el, er, ec;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (graph[i][j][k] == 'S')
						sl = i, sr = j, sc = k;
					else if (graph[i][j][k] == 'E')
						el = i, er = j, ec = k;
				}
			}
		}

		BFS(graph, sl, sr, sc, el, er, ec);

		cin >> L >> R >> C;
	}
}