#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<bool>> board;
int N, M;

bool check(int r, int c) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (r - i < 0 || c - j < 0)
				return false;
			if (!board[r - i][c - j])
				return false;
		}
	}
	return true;
}

int recur(int r, int c) {
	if (r == N)
		return 1;

	int nr = c + 1 == M ? r + 1 : r;
	int nc = c + 1 == M ? 0 : c + 1;

	int ret = 0;

	board[r][c] = 1;
	if(!check(r, c))
		ret += recur(nr, nc);
	board[r][c] = 0;
	ret += recur(nr, nc);
	return ret;
}

void solve() {
	cin >> N >> M;

	board = vector<vector<bool>>(N, vector<bool>(M));

	cout << recur(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}