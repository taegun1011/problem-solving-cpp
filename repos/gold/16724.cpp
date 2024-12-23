#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M;

vector<int> p;

int bijection(int r, int c) {
	return M * r + c;
}

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
}

int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
map<char, int> dM = { {'U',0},{'R',1},{'D',2},{'L',3} };
vector<string> board;

void DFS(int cr, int cc, int cp) {
	int i = dM[board[cr][cc]];
	int nr = cr + dir[i][0];
	int nc = cc + dir[i][1];

	int np = find(bijection(nr, nc));
	if (cp != np) {
		merge(np, cp);
		DFS(nr, nc, np);
	}
}

void solve() {
	cin >> N >> M;
	p.resize(N * M);
	for (int i = 0; i < N*M; i++)
		p[i] = i;

	string row;
	for (int i = 0; i < N;i++) {
		cin >> row;
		board.push_back(row);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int cur = bijection(i, j);
			int cp = find(cur);
			if (cp == cur)
				DFS(i, j, cp);
		}
	}

	int ans = 0;
	for (int i = 0; i < N*M; i++)
		if (p[i] == i)
			ans++;
	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}