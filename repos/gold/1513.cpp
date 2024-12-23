#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000007

int N, M;
vector<vector<int>> board;

int dp[51][51][51][51];

int re_dp(int r, int c, int prv, int left) {
	if (r == N || c == M || left < 0)
		return 0;
	if (r == N - 1 && c == M - 1)
		return !left;

	int& ret = dp[r][c][prv][left];
	if (ret != -1)
		return ret;

	ret = 0;
	if (r + 1 < N) {
		if (board[r + 1][c]) {
			if (board[r + 1][c] > prv)
				ret += re_dp(r + 1, c, board[r + 1][c], left - 1);
		}
		else
			ret += re_dp(r + 1, c, prv, left);
	}

	if (c + 1 < M) {
		if (board[r][c + 1]) {
			if (board[r][c + 1] > prv)
				ret += re_dp(r, c + 1, board[r][c + 1], left - 1);
		}
		else
			ret += re_dp(r, c + 1, prv, left);
	}

	return (ret %= MOD);
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int C;
	cin >> N >> M >> C;

	board = vector<vector<int>>(N, vector<int>(M));

	for (int i = 0; i < C; i++) {
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = i + 1;
	}

	for (int i = 0; i <= C; i++)
		cout << re_dp(0, 0, board[0][0], i - !!board[0][0]) << (i == C ? '\n' : ' ');
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}