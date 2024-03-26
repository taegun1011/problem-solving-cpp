#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void solve() {
	PII S, E;

	int N, H, D;
	cin >> N >> H >> D;

	vector<string> board(N);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'S')
				S = { i,j };
			else if (board[i][j] == 'E')
				E = { i,j };
		}
	}

	//visited에 방문 여부 대신 자원을 저장하는 게 핵심?
	vector<vector<int>> visited(N, vector<int>(N));
	visited[S.first][S.second] = H;
	
	queue<vector<int>> Q;
	Q.push({ S.first, S.second, H, 0, 0 });

	int ans = INT_MAX;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur[0], cc = cur[1], ch = cur[2], cu = cur[3], cd = cur[4];

		for (int i = 0; i < 4; i++) {
			int nr = dir[i][0] + cr;
			int nc = dir[i][1] + cc;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				continue;

			int nd = cd + 1;

			if (E == make_pair(nr, nc)) {
				ans = min(ans, nd);
				continue;
			}

			int nh = ch, nu = cu;

			if (board[nr][nc] == 'U')
				nu = D;

			if (nu)
				nu--;
			else
				nh--;

			if (nh && visited[nr][nc] < nh + nu) {
				visited[nr][nc] = nh + nu;
				Q.push({ nr, nc, nh, nu, nd });
			}
		}
	}

	cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}