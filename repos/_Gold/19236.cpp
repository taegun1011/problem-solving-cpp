#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int dir[9][2] = { 0,0,-1,0,-1,-1,0,-1,1,-1,1,0,1,1,0,1,-1,1 };

struct shark {
	int r;
	int c;
	int d;
	int sum;
};

vector<vector<int>> board(4, vector<int>(4));

bool check(int cr, int cc, int shr, int shc) {
	return cr >= 0 && cr < 4 && cc >= 0 && cc < 4 && !(cr == shr && cc == shc);
}

void swap(int r1, int c1, int r2, int c2, vector<PII>& fish_pos, vector<vector<int>>& board) {
	int f1 = board[r1][c1], f2 = board[r2][c2];
	board[r1][c1] = f2;
	board[r2][c2] = f1;
	fish_pos[f1] = { r2, c2 };
	fish_pos[f2] = { r1, c1 };
}

void fish_mv(shark sh, vector<vector<int>>& board, vector<PII>& fish_pos, vector<int>& fish_dir, vector<bool>& fish_dead) {
	for (int i = 1; i <= 16; i++) {
		if (fish_dead[i])
			continue;
		int cr = fish_pos[i].first, cc = fish_pos[i].second, cd = fish_dir[i];
		int cnt = 0;
		while (cnt < 8 && !check(cr + dir[cd][0], cc + dir[cd][1], sh.r, sh.c)) {
			cnt++;
			cd++;
			if (cd > 8)
				cd = 1;
		}
		fish_dir[i] = cd;
		if (cnt < 8)
			swap(cr, cc, cr + dir[cd][0], cc + dir[cd][1], fish_pos, board);
	}
}

int shark_mv(shark sh, vector<vector<int>> board, vector<PII> fish_pos, vector<int> fish_dir, vector<bool> fish_dead) {

	fish_mv(sh, board, fish_pos, fish_dir, fish_dead);

	vector<PII> nxt;
	int cr = sh.r + dir[sh.d][0], cc = sh.c + dir[sh.d][1];
	while (cr >= 0 && cr < 4 && cc >= 0 && cc < 4) {
		nxt.push_back({ cr, cc });
		cr += dir[sh.d][0];
		cc += dir[sh.d][1];
	}

	int ret = sh.sum;

	for (PII p : nxt) {
		shark nxt_sh = sh;
		nxt_sh.r = p.first;
		nxt_sh.c = p.second;

		if (fish_dead[board[p.first][p.second]])
			continue;

		fish_dead[board[p.first][p.second]] = true;
		nxt_sh.d = fish_dir[board[p.first][p.second]];
		nxt_sh.sum += board[p.first][p.second];
		ret = max(ret, shark_mv(nxt_sh, board, fish_pos, fish_dir, fish_dead));
		fish_dead[board[p.first][p.second]] = false;
	}

	return ret;
}

void solve() {
	vector<PII> fish_pos(17);
	vector<int> fish_dir(17);
	vector<bool> fish_dead(17);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			fish_dir[a] = b;
			fish_pos[a] = { i,j };
			board[i][j] = a;
		}

	shark sh = { 0, 0, fish_dir[board[0][0]], board[0][0] };
	fish_dead[board[0][0]] = 1;
	cout << shark_mv(sh, board, fish_pos, fish_dir, fish_dead) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}