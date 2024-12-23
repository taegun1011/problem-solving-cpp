#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//dir : 축, 행, 열
//위, 아래, 왼쪽, 오른쪽, 앞, 뒤
short dir[6][3] = { 0,0,-1,0,0,1,0,-1,0,0,1,0,1,0,0,-1,0,0 };

short graph[101][101][101];
int day[101][101][101];

int main() {
	FASTIO;

	int M, N, H;
	cin >> M >> N >> H;

	queue<tuple<int, int, int>> Q;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] == 1)
					Q.push({ i,j,k });
			}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int ch = get<0>(cur), cr = get<1>(cur), cc = get<2>(cur);

		for (int i = 0; i < 6; i++) {
			int nh = ch + dir[i][0], nr = cr + dir[i][1], nc = cc + dir[i][2];
			if (nh < 0 || nh >= H || nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nh][nr][nc] == 0 && !day[nh][nr][nc]) {
				day[nh][nr][nc] = day[ch][cr][cc] + 1;
				Q.push({ nh, nr, nc });
			}
		}
	}

	int mx = 0;
	bool flag = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				mx = max(mx, day[i][j][k]);
				if (graph[i][j][k] == 0 && !day[i][j][k])
					flag = 1;
			}
		}
	}

	cout << (flag ? -1 : mx) << endl;
}