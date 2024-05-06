#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

struct group {
	int size;
	int rainbow;
	int r;
	int c;
};

vector<group> arr;
vector<vector<int>> board;
int N, M;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

void scan();
group dfs(int cr, int cc, group g, vector<vector<bool>>& visited);
void refresh(vector<vector<bool>>& visited);
group find_max();
void erase(int cr, int cc, int color);
void fall();
void flipLR();
void transpose();

void solve() {
	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(N));

	for (auto& row : board)
		for (int& x : row)
			cin >> x;

	int sum = 0;

	scan();
	while (arr.size()) {
		group max_g = find_max();
		sum += max_g.size * max_g.size;
		erase(max_g.r, max_g.c, board[max_g.r][max_g.c]);
		fall();
		//rotate
		flipLR();
		transpose();
		fall();

		scan();
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}

group dfs(int cr, int cc, group g, vector<vector<bool>>& visited) {
	visited[cr][cc] = true;

	g.size = 1;
	g.rainbow = board[cr][cc] == 0;

	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0];
		int nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;
		if (!visited[nr][nc] && (!board[nr][nc] || board[nr][nc] == board[g.r][g.c])) {
			group res = dfs(nr, nc, g, visited);
			g.size += res.size;
			g.rainbow += res.rainbow;
		}
	}

	return g;
}

void erase(int cr, int cc, int color) {
	board[cr][cc] = -2;

	for (int i = 0; i < 4; i++) {
		int nr = cr + dir[i][0];
		int nc = cc + dir[i][1];
		if (nr < 0 || nr >= N || nc < 0 || nc >= N)
			continue;
		if (board[nr][nc] == 0 || board[nr][nc] == color)
			erase(nr, nc,color);
	}
}

void refresh(vector<vector<bool>>& visited) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!board[i][j])
				visited[i][j] = 0;
}

void scan() {
	vector<vector<bool>> visited(N, vector<bool>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j] && board[i][j] > 0) {
				group g = dfs(i, j, { 0,0,i,j }, visited);
				if (g.size > 1)
					arr.push_back(g);
				refresh(visited);
			}

}

group find_max() {
	group max = { 0,0,0,0 };
	for (group g : arr) {
		if (g.size > max.size)
			max = g;
		else if (g.size == max.size) {
			if (g.rainbow > max.rainbow)
				max = g;
			else if (g.rainbow == max.rainbow) {
				if (g.r > max.r)
					max = g;
				else if (g.r == max.r) {
					if (g.c > max.c)
						max = g;
				}
			}
		}
	}

	arr.clear();
	return max;
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (board[j][i] == -1)
				continue;
			int k = j;
			while (k + 1 < N && board[k + 1][i] == -2) {
				board[k + 1][i] = board[k][i];
				board[k][i] = -2;
				k++;
			}
		}
	}
}

void flipLR() {
	vector<vector<int>> new_board(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			new_board[i][j] = board[i][N - 1 - j];

	board = new_board;
}

void transpose() {
	vector<vector<int>> new_board(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			new_board[i][j] = board[j][i];

	board = new_board;
}