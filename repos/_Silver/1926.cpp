#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int visited[501][501];
int N, M;

int BFS(vector<vector<int>>& graph, int row, int col) {
	queue<pair<int, int>> Q;
	Q.push({ row, col });
	visited[row][col] = 1;
	int ret = 1;
	
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int c_row = cur.first, c_col = cur.second;
		for (int i = 0; i < 4; i++) {
			int n_row = c_row + dir[i][0], n_col = c_col + dir[i][1];
			if (n_row < 0 || n_row >= N || n_col < 0 || n_col >= M) continue;
			if (graph[n_row][n_col] && !visited[n_row][n_col]) {
				ret++;
				visited[n_row][n_col] = 1;
				Q.push({ n_row, n_col });
			}
		}
	}

	return ret;
}

int main() {
	FASTIO;
	
	cin >> N >> M;

	vector<vector<int>> graph(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	int cnt = 0, mx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && graph[i][j]) {
				cnt++;
				mx = max(mx, BFS(graph, i, j));
			}
		}
	}

	cout << cnt << '\n' << mx << endl;
}