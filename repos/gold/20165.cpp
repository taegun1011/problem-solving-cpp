#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

map<char, int> MAP = { {'N', 0},{'E', 1}, {'S', 2}, {'W', 3} };
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int N, M, R;

bool check(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

void solve() {
	cin >> N >> M >> R;

	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));

	for (auto& row : board)
		for (int& x : row)
			cin >> x;

	int sum = 0;
	while (R--) {
		int cr, cc, d;
		char D;
		cin >> cr >> cc >> D;
		d = MAP[D];

		queue<PII> Q;
		Q.push({ cr - 1,cc - 1 });

		while (!Q.empty()) {
			PII cur = Q.front();
			Q.pop();
			cr = cur.first;
			cc = cur.second;

			int len = board[cr][cc];
			for (int i = 0; i < len; i++) {
				int nr = cr + dir[d][0] * i, nc = cc + dir[d][1] * i;
				if (check(nr, nc) && !visited[nr][nc]) {
					visited[nr][nc] = true;
					sum++;
					Q.push({ nr, nc });
				}
			}
		}

		cin >> cr >> cc;
		visited[cr - 1][cc - 1] = false;
	}

	cout << sum << '\n';
	for (auto row : visited) {
		for (bool x : row)
			cout << (x ? 'F' : 'S') << ' ';
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