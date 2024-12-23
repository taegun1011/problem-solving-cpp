#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[2][11][1001][1001];
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

struct pos {
	int day;
	int floor;
	int row;
	int col;
};

int main() {
	memset(dist, -1, sizeof(dist));
	FASTIO;

	int N, M, K;
	cin >> N >> M >> K;

	vector<string> graph(N);
	for (int i = 0; i < N; i++)
		cin >> graph[i];

	queue<pos> Q;
	Q.push({ 0, 0, 0, 0 });
	dist[0][0][0][0] = 1;

	//³·0¹ã1

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int now = cur.day, cf = cur.floor, cr = cur.row, cc = cur.col;
		if (cr == N - 1 && cc == M - 1) continue;
		
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nr][nc] == '0') {
				if (dist[1 - now][cf][nr][nc] < 0) {
					dist[1 - now][cf][nr][nc] = dist[now][cf][cr][cc] + 1;
					Q.push({ 1 - now,cf,nr,nc });
				}
			}
			else {
				if (now || cf == K) continue;
				if (dist[1 - now][cf + 1][nr][nc] < 0) {
					dist[1 - now][cf + 1][nr][nc] = dist[now][cf][cr][cc] + 1;
					Q.push({ 1 - now,cf + 1,nr,nc });
				}
			}
		}
		if (dist[1 - now][cf][cr][cc] < 0) {
			dist[1 - now][cf][cr][cc] = dist[now][cf][cr][cc] + 1;
			Q.push({ 1 - now,cf,cr,cc });
		}
	}

	int ans = -1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= K; j++) {
			if (N < 1 || M < 1) continue;
			int temp = dist[i][j][N - 1][M - 1];
			if (ans < 0)
				ans = temp;
			else if (temp >= 0)
				ans = min(ans, temp);
		}
	}

	cout << ans << endl;
}