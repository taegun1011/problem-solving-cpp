#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 9 파핑파핑 지뢰찾기

#define PII pair<int, int>

int N;
int dir[8][2] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1 };

void bfs(int cr, int cc, vector<vector<int>>& cnt, vector<vector<bool>>& visited) {
	queue<PII> Q;
	Q.push({ cr, cc });

	while (!Q.empty()) {
		PII cur = Q.front();
		Q.pop();

		cr = cur.first, cc = cur.second;
		for (int i = 0; i < 8; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N)
				continue;
			if (!visited[nr][nc] && !cnt[nr][nc])
				Q.push({ nr, nc });
			visited[nr][nc] = 1;
		}
	}
}

int solve() {
	cin >> N;

	vector<vector<char>> board(N, vector<char>(N));
	for (auto& row : board)
		for (char& x : row)
			cin >> x;
	vector<vector<int>> cnt(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 8; k++) {
				int r = i + dir[k][0], c = j + dir[k][1];
				if (r < 0 || r >= N || c < 0 || c >= N)
					continue;
				if (board[r][c] == '*')
					cnt[i][j]++;
			}
		}
	}

	vector<vector<bool>> visited(N, vector<bool>(N));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '.' && !cnt[i][j] && !visited[i][j]) {
				ans++;
				bfs(i, j, cnt, visited);
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == '.' && cnt[i][j] && !visited[i][j])
				ans++;
	
	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}