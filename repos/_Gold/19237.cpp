#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

vector<vector<int>> board;
vector<vector<PII>> scent;
vector<PII> position;
vector<int> direction;
vector<bool> is_dead;

//크기 [M][4][4]
vector<vector<vector<int>>> move_priority;

//1부터 위, 아래, 왼쪽, 오른쪽
int dir[5][2] = { 0,0,-1,0,1,0,0,-1,0,1 };

int N, M, K, cnt;
void spread() {
	for (int i = 1; i <= M; i++)
		if (!is_dead[i])
			scent[position[i].first][position[i].second] = { i, K };
}

void move() {
	vector<vector<int>> temp(N, vector<int>(N));

	for (int i = 1; i <= M; i++) {
		if (is_dead[i])
			continue;

		PII nxt = { -1, -1 };
		int cr = position[i].first, cc = position[i].second;
		for (int j = 0; j < 4; j++) {

			//i번 상어의 현재 위치 direction[i]에 대한 우선순위 중 j번째 방향
			int k = move_priority[i][direction[i] - 1][j];
			int nr = cr + dir[k][0], nc = cc + dir[k][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				continue;
			if (!scent[nr][nc].first) {
				nxt = { nr, nc };
				direction[i] = k;
				break;
			}
		}

		if (nxt.first == -1) {
			for (int j = 0; j < 4; j++) {
				int k = move_priority[i][direction[i] - 1][j];
				int nr = cr + dir[k][0], nc = cc + dir[k][1];
				if (nr < 0 || nr >= N || nc < 0 || nc >= N)
					continue;
				if (scent[nr][nc].first == i) {
					nxt = { nr, nc };
					direction[i] = k;
					break;
				}
			}
		}

		position[i] = nxt;

		if (temp[nxt.first][nxt.second]) {
			is_dead[i] = true;
			cnt--;
		}
		else
			temp[nxt.first][nxt.second] = i;
	}
	board = temp;
}

void clear() {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (scent[i][j].second)
				if (--scent[i][j].second == 0)
					scent[i][j].first = 0;

}

void solve() {
	cin >> N >> M >> K;

	board = vector<vector<int>>(N, vector<int>(N));
	scent = vector<vector<PII>>(N, vector<PII>(N));
	position = vector<PII>(M + 1);
	is_dead = vector<bool>(M + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j])
				position[board[i][j]] = { i,j };
		}
	}

	direction = vector<int>(M + 1);
	for (int i = 1; i <= M; i++)
		cin >> direction[i];

	move_priority = vector<vector<vector<int>>>(M + 1, vector<vector<int>>(4, vector<int>(4)));
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> move_priority[i][j][k];

	int ans = 0;
	cnt = M;
	while (++ans <= 1000) {
		spread();
		move();
		clear();
		if (cnt == 1)
			break;
	}

	cout << (ans > 1000 ? -1 : ans) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}