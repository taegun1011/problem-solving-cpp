#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[11][1001][1001];
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	memset(dist, -1, sizeof(dist));

	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	if (N < 1 || M < 1)
		return -1;

	vector<string> graph(N);
	for (int i = 0; i < N; i++)
		cin >> graph[i];
		

	queue<tuple<int,int,int>> Q;
	Q.push({ 0,0,0 });
	dist[0][0][0] = 1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cf = get<0>(cur), cr = get<1>(cur), cc = get<2>(cur);

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nr][nc] == '0') {
				if (dist[cf][nr][nc] > 0) continue;
				dist[cf][nr][nc] = dist[cf][cr][cc] + 1;
				Q.push({ cf,nr,nc });
			}
			else if (cf < K) {
				if (dist[cf + 1][nr][nc] > 0) continue;
				dist[cf + 1][nr][nc] = dist[cf][cr][cc] + 1;
				Q.push({ cf + 1,nr,nc });
			}
		}
	}

	int ans = dist[0][N - 1][M - 1];
	for (int i = 0; i <= K; i++) {
		if (ans == -1)
			ans = dist[i][N - 1][M - 1];
		else if (dist[i][N - 1][M - 1] >= 0)
			ans = min(ans, dist[i][N - 1][M - 1]);
	}
	cout << ans << endl;
}