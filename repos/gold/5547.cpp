#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

//더 깔끔한 풀이 : 외곽에서 한번 dfs를 수행해서 '밖에 있는 빈 건물'을 체크한다

int N, M;

int ans;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int dir[2][6][2] = { {-1,0,-1,1,0,1,1,1,1,0,0,-1},{-1,-1,-1,0,0,1,1,0,1,-1,0,-1} };

void dfs(int cr, int cc) {
	visited[cr][cc] = true;

	ans += 6;
	for (int i = 0; i < 6; i++) {
		int nr = dir[cr % 2][i][0] + cr, nc = dir[cr % 2][i][1] + cc;
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;
		if (graph[nr][nc]) {
			ans--;
			if (!visited[nr][nc])
				dfs(nr, nc);
		}
	}
}

bool flag = true;
int cnt;

void dfs_inside(int cr, int cc) {
	if (cr == 0 || cr + 1 == N || cc == 0 || cc + 1 == M) {
		flag = false;
		return;
	}
	visited[cr][cc] = true;

	cnt += 6;
	for (int i = 0; i < 6; i++) {
		int nr = dir[cr % 2][i][0] + cr, nc = dir[cr % 2][i][1] + cc;
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;
		
		if (!graph[nr][nc]) {
			cnt--;
			if (!visited[nr][nc])
				dfs_inside(nr, nc);
		}
	}
}

void solve() {
	cin >> M >> N;
	graph = vector<vector<int>>(N, vector<int>(M));
	for (auto& row : graph)
		for (int& x : row)
			cin >> x;

	visited = vector<vector<bool>>(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (graph[i][j] && !visited[i][j])
				dfs(i, j);

	for (int i = 1; i + 1 < N; i++)
		for (int j = 1; j + 1 < M; j++) {
			if (!graph[i][j] && !visited[i][j]) {
				flag = true;
				cnt = 0;
				dfs_inside(i, j);
				if (flag)
					ans -= cnt;
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