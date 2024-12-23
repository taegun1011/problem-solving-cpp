#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int dist[101][101];
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	vector<string> graph(N);

	for (int i = 0; i < N; i++)
		cin >> graph[i];

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (graph[nr][nc] == '1' && !dist[nr][nc]) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr,nc });
			}
		}
	}
	cout << dist[N - 1][M - 1] << endl;
}