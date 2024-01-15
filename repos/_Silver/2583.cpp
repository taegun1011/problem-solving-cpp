#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int M, N, K;

int BFS(vector<vector<bool>>& visited, int sr, int sc) {
	queue<pair<int, int>> Q;
	int ret = 1;

	visited[sr][sc] = 1;
	Q.push({ sr, sc });

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;

			if (!visited[nr][nc]) {
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
	cin >> M >> N >> K;
	
	vector<vector<bool>> visited(M, vector<bool>(N));

	int sr, sc, er, ec;
	while (K) {
		K--;
		cin >> sc >> sr >> ec >> er;
		sr = M - sr; er = M - er;

		for (int i = er; i < sr; i++)
			for (int j = sc; j < ec; j++)
				visited[i][j] = 1;
	}

	vector<int> ans;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j])
				ans.push_back(BFS(visited, i, j));
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int i : ans)
		cout << i << ' ';
}