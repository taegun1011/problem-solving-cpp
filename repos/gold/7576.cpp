#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	FASTIO;

	queue<pair<int, int>> Q;

	int N, M;
	cin >> M >> N;

	vector<vector<int>> graph(N, vector<int>(M));
	vector<vector<int>> day(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				Q.push({ i,j });
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (!graph[nr][nc] && !day[nr][nc]) {
				day[nr][nc] = day[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	int mx = 0, flag = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M;j++) {
			mx = max(mx, day[i][j]);
			if (!day[i][j] && !graph[i][j])
				flag = 1;
		}

	cout << (flag ? -1 : mx) << endl;
}