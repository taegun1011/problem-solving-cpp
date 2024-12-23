#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
int N, L, R;
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

vector<vector<int>> graph, result;
vector<vector<bool>> visited;

PII dfs(int cr, int cc) {
	visited[cr][cc] = true;

	PII ret = { graph[cr][cc], 1 };
	for (int i = 0; i < 4; i++) {
		int nr = dir[i][0] + cr;
		int nc = dir[i][1] + cc;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
			continue;
		int diff = abs(graph[nr][nc] - graph[cr][cc]);
		if (diff >= L && diff <= R) {
			PII temp = dfs(nr, nc);
			ret.first += temp.first;
			ret.second += temp.second;
		}
	}

	return ret;
}

void set(int cr, int cc, int value) {
	result[cr][cc] = value;
	for (int i = 0; i < 4; i++) {
		int nr = dir[i][0] + cr;
		int nc = dir[i][1] + cc;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N || result[nr][nc] >= 0)
			continue;
		int diff = abs(graph[nr][nc] - graph[cr][cc]);
		if (diff >= L && diff <= R)
			::set(nr, nc, value);
	}
}

void solve() {
	cin >> N >> L >> R;

	graph = vector<vector<int>>(N, vector<int>(N));
	for (auto& row : graph)
		for (int& x : row)
			cin >> x;

	int days = -1;
	bool moved = false;
	do {
		moved = false;
		visited = vector<vector<bool>>(N, vector<bool>(N));
		result = vector<vector<int>>(N, vector<int>(N, -1));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					PII p = dfs(i, j);
					if (p.second > 1)
						moved = true;
					::set(i, j, p.first / p.second);
				}
			}
		}

		graph = result;
		days++;

	} while (moved);

	cout << days << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}