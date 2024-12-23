#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

//i번 물건에 j번 바람(상우하좌)이 들어왔을 때 변환되는 방향
int conv[5][4] = {
	{0,1,2,3},
	{0,3,2,1},
	{2,1,0,3},
	{1,0,3,2},
	{3,2,1,0}
};

int board[2001][2001];
bool visited[2001][2001][4];
void solve() {
	cin >> N >> M;
	queue<pair<PII, int>> Q;

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				cnt++;
				for (int k = 0; k < 4; k++) {
					visited[i][j][k] = true;
					Q.push({ {i,j},k });
				}
			}
		}
	}

	while (!Q.empty()) {
		pair<PII, int> p = Q.front();
		Q.pop();

		int cr = p.first.first, cc = p.first.second, cd = p.second;

		int nd = board[cr][cc] == 9 ? cd : conv[board[cr][cc]][cd];
		int nr = dir[nd][0] + cr, nc = dir[nd][1] + cc;
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc][nd])
			continue;

		bool flag = true;
		for (int i = 0; i < 4; i++)
			if (visited[nr][nc][i])
				flag = false;
		if (flag)
			cnt++;
		visited[nr][nc][nd] = true;
		Q.push({ {nr, nc},nd });
	}

	cout << cnt << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}