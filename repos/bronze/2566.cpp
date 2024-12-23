#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<int>> board(9, vector<int>(9));

	int i, j;
	for (i = 0; i < 9;i++) {
		for (j = 0; j < 9;j++) {
			cin >> board[i][j];
		}
	}

	int max = 0, max_r = 0, max_c = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (board[i][j] > max) {
				max = board[i][j];
				max_r = i;
				max_c = j;
			}
		}
	}

	printf("%d\n%d %d\n", max, max_r + 1, max_c + 1);
}