#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

//					けし						  け					け					しけ
//					  け						けし					しけ					け
int dir[4][3][2] = { {0,-1,0,0,1,0},{-1,0,0,0,0,-1},{-1,0,0,0,0,1},{0,0,0,1,1,0} };

vector<vector<int>> board;
vector<vector<bool>> visited;

void clear(int cr, int cc, int d, int i) {
	while (--i >= 0) {
		int nr = cr + dir[d][i][0], nc = cc + dir[d][i][1];
		visited[nr][nc] = false;
	}
}

int check(int cr, int cc, int d) {
	int ret = 0;

	int i;
	for (i = 0; i < 3; i++) {
		int nr = cr + dir[d][i][0], nc = cc + dir[d][i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc])
			break;
		visited[nr][nc] = true;
		ret += board[nr][nc];
		if (nr == cr && nc == cc)
			ret += board[nr][nc];
	}

	if (i != 3) {
		clear(cr, cc, d, i);
		return 0;
	}

	return ret;
}

int recur(int cr, int cc) {
	if (cr == N)
		return 0;

	int ans = 0;
	int nr = cr, nc = cc + 1;
	if (nc == M) {
		nc = 0;
		nr += 1;
	}

	for (int i = 0; i < 4; i++) {
		int res = check(cr, cc, i);
		if (res) {
			ans = max(ans, recur(nr, nc) + res);
			clear(cr, cc, i, 3);
		}
	}
	ans = max(ans, recur(nr, nc));

	return ans;
}

void solve() {
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<bool>>(N, vector<bool>(M));
	for (auto& row : board)
		for (int& x : row)
			cin >> x;

	cout << recur(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}