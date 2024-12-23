#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
bool visited[26][26];
int N;

int BFS(vector<string>& graph, int sr, int sc) {
	visited[sr][sc] = 1;

	queue<pair<int, int>> Q;
	int ret = 1;
	
	Q.push({ sr,sc });
	
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (graph[nr][nc] == '1' && !visited[nr][nc]) {
				visited[nr][nc] = 1;
				ret++;
				Q.push({ nr, nc });
			}
		}
	}

	return ret;
}

int main() {
	FASTIO;
	cin >> N;

	vector<string> graph(N);
	
	for (int i = 0; i < N; i++)
		cin >> graph[i];
	
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] == '1' && !visited[i][j]) {
				ans.push_back(BFS(graph, i, j));
			}

		}
	}
	
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << endl;
}