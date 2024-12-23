#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int dir[5][2] = { -1,0,0,1,1,0,0,-1,0,0 };

void solve() {
	int R, C, N;
	cin >> R >> C >> N;

	vector<string> board_origin(R);

	vector<vector<string>> board(4, vector<string>(R));
	for (int i = 0; i < 4; i++)
		board[i] = vector<string>(R, string(C, 'O'));

	vector<string> bomb1(R, string(C, '.')), bomb2(R, string(C, '.'));

	//1段
	for (int i = 0; i < R; i++) {
		cin >> board_origin[i];
		for (int j = 0; j < C; j++) {
			if (board_origin[i][j] == 'O')
				bomb1[i][j] = 'O';
		}
	}

	//2段
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (bomb1[i][j] == '.')
				bomb2[i][j] = 'O';

	//3段
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(bomb1[i][j] == 'O')
				for (int k = 0; k < 5; k++) {
					int nr = i + dir[k][0];
					int nc = j + dir[k][1];
					if (nr < 0 || nr >= R || nc < 0 || nc >= C)
						continue;
					bomb2[nr][nc] = board[3][nr][nc] = '.';
				}
		}
	}

	//5段
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (bomb2[i][j] == 'O') {
				for (int k = 0; k < 5; k++) {
					int nr = i + dir[k][0];
					int nc = j + dir[k][1];
					if (nr < 0 || nr >= R || nc < 0 || nc >= C)
						continue;
					board[1][nr][nc] = '.';
				}
			}
		}
	}

	vector<string> answer(N == 1 ? board_origin : board[N % 4]);
	for (string row : answer)
		cout << row << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}