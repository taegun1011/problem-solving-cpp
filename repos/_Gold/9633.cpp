#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

struct coord{
	int row;
	int col;
};

int Size;

bool indep(vector<struct coord>& queen, int row, int col);
int placeQueen(vector<struct coord> queen, int row);

int main() {
	cin >> Size;


	vector<struct coord> queen;

	cout << placeQueen(queen, 0) << endl;

}

int placeQueen( vector<struct coord> queen, int row) {
	if (row == Size - 1) {
		for (int j = 0; j < Size; j++) {
			if (indep(queen, row, j)) return 1;
		}
		return 0;
	}

	int res = 0;

	for (int j = 0; j < Size; j++) {
		if (indep(queen, row, j)) {
			queen.push_back({ row,j });
			res += placeQueen(queen, row + 1);
			queen.pop_back();
		}
	}

	return res;
}

bool indep(vector<struct coord>& queen, int row, int col) {
	int n = queen.size();
	if (!n) return true;

	for (int i = 0; i < n; i++) {
		if (queen[i].row == row) return false;
		if (queen[i].col == col) return false;
		if (queen[i].row - queen[i].col == row - col) return false;
		if (queen[i].row + queen[i].col == row + col) return false;
	}

	return true;
}