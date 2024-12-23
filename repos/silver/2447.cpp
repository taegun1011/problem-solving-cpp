#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void draw(char pattern, int row_start, int col_start, int size);
char** star;

int main() {
	int n;
	cin >> n;
	star = new char* [n + 1];
	for (int i = 1; i <= n; i++) {
		star[i] = new char[n + 1];
	}
	draw('*', 1, 1, n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}

void draw(char pattern, int row_start, int col_start, int size) {
	if (size == 3) {
		for (int i = row_start; i <= row_start + size - 1; i++)
			for (int j = col_start; j <= col_start + size - 1; j++)
				star[i][j] = (j - col_start == 1 && i - row_start == 1) ? ' ' : pattern;
		return;
	}
	size /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				draw(' ', row_start + size, col_start + size, size);
				continue;
			}
			draw(pattern, row_start + i * size, col_start + j * size, size);
		}
	}
}