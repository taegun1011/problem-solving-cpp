#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int visited[101][101];

void solve() {
	memset(visited, 0, sizeof(visited));

	int N, M;
	cin >> N >> M;

	vector<string> graph(N);

	for (int i = 0; i < N; i++)
		cin >> graph[i];
	
	queue<pair<int, int>> Q;
	vector<pair<int, int>> D[26];

	vector<bool> key(26);
	string keylist;
	cin >> keylist;
	if (keylist != "0") {
		for (char c : keylist)
			key[c - 'a'] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp = graph[i][j];
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
				visited[i][j] = 1;
				if (temp == '.' || (temp >= 'a' && temp <= 'z') || temp == '$')
					Q.push({ i,j });
				if (temp >= 'A' && temp <= 'Z' && key[temp - 'A'])
					Q.push({ i,j });
			}

			if (temp >= 'A' && temp <= 'Z')
				D[temp - 'A'].push_back({ i,j });
		}
	}

	int ans = 0;
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		char temp = graph[cr][cc];
		if (temp == '$')
			ans++;

		else if (temp >= 'a' && temp <= 'z') {
			key[temp - 'a'] = 1;
			for (auto p : D[temp - 'a'])
				if (visited[p.first][p.second])
					Q.push({ p.first, p.second });
		}

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (!visited[nr][nc]) {
				visited[nr][nc] = 1;
				char temp = graph[nr][nc];
				if (temp == '.' || (temp >= 'a' && temp <= 'z') || temp == '$')
					Q.push({ nr,nc });
				if (temp >= 'A' && temp <= 'Z' && key[graph[nr][nc] - 'A'])
					Q.push({ nr, nc });
			}
		}
	}

	cout << ans << endl;
}

int main() {
	FASTIO;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}