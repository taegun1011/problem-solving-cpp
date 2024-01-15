#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int N, M;

int DFS(vector<vector<int>>& graph, vector<vector<bool>>& visited, int cr, int cc) {
	visited[cr][cc] = 1;

	int ret = 1;

	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0], nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

		if(graph[nr][nc] > 0 && !visited[nr][nc])
			ret += DFS(graph, visited, nr, nc);
	}

	return ret;
}

int main() {
	FASTIO;

	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));
	vector<vector<int>> melt(N, vector<int>(M));

	queue<tuple<int, int, int>> Q;

	int size = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j]) {
				Q.push({ i,j,1 });
				size++;
			}
		}

	int now = 1;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = get<0>(cur), cc = get<1>(cur), cy = get<2>(cur);
		int& h = graph[cr][cc];

		if (now < cy) {

			vector<vector<bool>> visited(N, vector<bool>(M));
			if (DFS(graph, visited, cr, cc) != size) {
				cout << now << endl;
				return 0;
			}

			now = cy;
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nr][nc] == 0 && melt[nr][nc] < cy) {
				h = (h > 0 ? h - 1 : 0);
				if (!h) {
					melt[cr][cc] = cy;
					size--;
					break;
				}
			}
		}
		if (h)
			Q.push({ cr,cc,cy + 1 });

	}

	cout << 0 << endl;
}