#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M;

vector<string> board;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int getSize(int cr, int cc, vector<vector<int>>& visited) {
	visited[cr][cc] = true;
	
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0];
		int nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == '1')
			continue;
		if(!visited[nr][nc])
			ret += getSize(nr, nc, visited);
	}

	return ret;
}

void fill(int cr, int cc, vector<vector<int>>& sz, int val, vector<vector<int>>& no, int idx) {
	sz[cr][cc] = val;
	no[cr][cc] = idx;

	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0];
		int nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == '1')
			continue;
		if (!sz[nr][nc])
			fill(nr, nc, sz, val, no, idx);
	}
}

void solve() {
	cin >> N >> M;
	
	vector<vector<int>> sz(N, vector<int>(M));
	vector<vector<int>> no(N, vector<int>(M));
	vector<vector<int>> visited(N, vector<int>(M));

	string row;
	for (int i = 0; i < N; i++) {
		cin >> row;
		board.push_back(row);
	}

	int idx = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] == '0' && !sz[i][j])
				fill(i, j, sz, getSize(i, j, visited), no, idx++);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '0')
				cout << 0;
			else {
				int sum = 1;
				set<int> S;
				for (int k = 0; k < 4; k++) {
					int nr = i + dir[k][0];
					int nc = j + dir[k][1];
					if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == '1')
						continue;
					int nn = no[nr][nc];
					if (S.find(nn) == S.end()) {
						S.insert(nn);
						sum += sz[nr][nc];
						sum %= 10;
					}
				}
				cout << sum;
			}
		}
		cout << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}