#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int BFS(vector<vector<int>>& graph, int h) {
	bool visited[101][101] = { 0, };
	int ret = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && graph[i][j] > h) {
				visited[i][j] = 1;
				ret++;
				queue<pair<int, int>> Q;
				Q.push({ i,j });

				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					int cr = cur.first, cc = cur.second;
					for (int i = 0; i < 4; i++) {
						int nr = cr + dir[i][0], nc = cc + dir[i][1];

						if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

						if (!visited[nr][nc] && graph[nr][nc] > h) {
							visited[nr][nc] = 1;
							Q.push({ nr,nc });
						}
					}
				}
			}
		}
	}

	return ret;
}

int main() {
	FASTIO;

	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N));

	int MAX = 1;
	for (auto &row : graph)
		for (int& cell : row) {
			cin >> cell;
			MAX = max(MAX, cell);
		}

	int ans = 0;
	for (int i = 0; i < MAX; i++)
		ans = max(ans, BFS(graph, i));

	cout << ans << endl;
}