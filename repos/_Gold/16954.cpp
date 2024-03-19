#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int dir[9][2] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,0,0 };

void solve() {
	vector<vector<string>> graph(9, vector<string> (8));

	for (int i = 0; i < 8; i++)
		cin >> graph[0][i];

	for (int i = 1; i <= 8; i++) {
		graph[i][0] = "........";
		for (int j = 1; j < 8; j++)
			graph[i][j] = graph[i - 1][j - 1];
	}

	vector<int> wall(9);
	for (int i = 0; i <= 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
				if (graph[i][j][k] == '#')
					wall[i]++;

	queue<pair<PII, int>> Q;

	int last = -1, ans = 0;

	Q.push({ { 7,0 }, 0 });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first.first;
		int cc = cur.first.second;
		int ct = cur.second;

		if (ct != last) {
			if (!wall[ct]) {
				ans = 1;
				break;
			}
			last = ct;
		}

		int nt = ct + 1;
		for (int i = 0; i < 9; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];
			if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
				continue;
			if (graph[ct][nr][nc] == '#' || graph[nt][nr][nc] == '#')
				continue;
			Q.push({ {nr, nc}, nt });
		}
	}

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