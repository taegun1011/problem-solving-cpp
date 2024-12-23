#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	FASTIO;

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>(N + 1)), visited(N + 1, vector<int>(N + 1));
	queue<pair<int, int>> Q;
	Q.push({ 1,1 });
	graph[1][1] = visited[1][1] = 1;

	//x,y 방 => y * 100 + x
	vector<vector<pair<int, int>>> sw(10101);
	int x, y, a, b;
	while (M) {
		M--;
		cin >> x >> y >> a >> b;

		sw[y * 100 + x].push_back({ b,a });
	}

	while (!Q.empty()) {
		//불을 켰는데 갈 수 있는 곳이면 이동한다

		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;

			if (visited[nr][nc]) continue;
			visited[nr][nc] = 1;
			if (graph[nr][nc])
				Q.push({ nr,nc });
		}

		for (auto p : sw[cr * 100 + cc]) {
			if (graph[p.first][p.second]) continue;

			graph[p.first][p.second] = 1;
			if (visited[p.first][p.second])
				Q.push({ p.first,p.second });
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (graph[i][j])
				cnt++;

	cout << cnt << endl;
}