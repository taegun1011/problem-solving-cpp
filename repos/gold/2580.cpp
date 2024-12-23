#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int board[9][9];
bool fin = false;

void makeBoard(int cr, int cc) {

	if (cr == 9) {
		if (!fin) {
			fin = true;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << board[i][j] << ' ';
				cout << '\n';
			}
		}
		return;
	}

	int nc = cc == 8 ? 0 : cc + 1;
	int nr = nc ? cr : cr + 1;
	if (board[cr][cc])
		makeBoard(nr, nc);
	else {
		bool visited[10] = { 0, };
		for (int i = 0; i < 9; i++) {
			visited[board[cr][i]] = true;
			visited[board[i][cc]] = true;
		}

		int sr = cr / 3 * 3, sc = cc / 3 * 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				visited[board[sr + i][sc + j]] = true;

		for (int i = 1; i <= 9; i++) {
			if (visited[i])
				continue;
			board[cr][cc] = i;
			makeBoard(nr, nc);
			board[cr][cc] = 0;
		}
	}
}

void solve() {
	
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];

	makeBoard(0, 0);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}