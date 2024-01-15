#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define min(a,b) {(a)>=(b) ? (b) : (a)}

int check8x8(char** board, int row_start, int col_start);

int main() {
	int m, n;
	std::cin >> m >> n;
	char** board = new char* [m];

	int i, j;
	char temp;
	for (i = 0; i < m; i++)
		board[i] = new char [n];

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			std::cin >> board[i][j];
		}
	}
	int min_num_paint = 63;
	for (i = 0; i <= m - 8; i++) {
		for (j = 0; j <= n - 8; j++) {
			min_num_paint = min(min_num_paint, check8x8(board, i, j));
		}
	}
	std::cout << min_num_paint << std::endl;

	return 0;
}

int check8x8(char** board, int row, int col) {
	char basecolor = 'B';
	int num_paint_b = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[row + i][col + j] != basecolor)
					num_paint_b++;
			}
			else
				if (board[row + i][col + j] == basecolor)
					num_paint_b++;
		}
	}

	basecolor = 'W';
	int num_paint_w = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[row + i][col + j] != basecolor)
					num_paint_w++;
			}
			else
				if (board[row + i][col + j] == basecolor)
					num_paint_w++;
		}
	}
	return min(num_paint_b,num_paint_w);
}