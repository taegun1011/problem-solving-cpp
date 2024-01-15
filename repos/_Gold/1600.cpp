#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//12시 방향부터 순서대로
short dir[12][2] = { -1,0,-2,1,-1,2,0,1,1,2,2,1,1,0,2,-1,1,-2,0,-1,-1,-2,-2,-1 };

int dist[31][201][201];

int main() {
	FASTIO;

	int N, M, K;
	cin >> K >> M >> N;

	vector<vector<int>> graph(N, vector<int>(M));
	for (auto& row : graph)
		for (int& cell : row)
			cin >> cell;

	queue<tuple<int, int, int>> Q;
	Q.push({ 0,0,0 });

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cf = get<0>(cur), cr = get<1>(cur), cc = get<2>(cur);
		int inc = (cf < K ? 1 : 3);
		for (int i = 0; i < 12; i += inc) {
			int nf = cf, nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (i % 3)
				nf++;

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nr][nc] == 0 && !dist[nf][nr][nc]) {
				dist[nf][nr][nc] = dist[cf][cr][cc] + 1;
				Q.push({ nf, nr, nc });
			}
		}
	}

	int ans = (N == 1 && M == 1 ? 0 : INT_MAX);
	for (int i = 0; i <= K; i++)
		if (dist[i][N - 1][M - 1])
			ans = min(ans, dist[i][N - 1][M - 1]);

	cout << (ans == INT_MAX ? -1 : ans) << endl;
}