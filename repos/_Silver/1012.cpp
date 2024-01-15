#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void solve() {
	int M, N, K;
	bool graph[51][51] = { 0, };
	bool visited[51][51] = { 0, };

	cin >> M >> N >> K;

	int X, Y;
	while (K) {
		K--;
		cin >> X >> Y;
		graph[Y][X] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && graph[i][j]) {
				cnt++;
				queue<pair<int, int>> Q;

				visited[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();

					int cr = cur.first, cc = cur.second;
					for (int i = 0; i < 4; i++) {
						int nr = cr + dir[i][0], nc = cc + dir[i][1];
						if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

						if (!visited[nr][nc] && graph[nr][nc]) {
							visited[nr][nc] = 1;
							Q.push({ nr, nc });
						}
					}
				}
			}
		}
	}

	cout << cnt << endl;
}

int main() {
	FASTIO;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}