#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dist[2][1001][1001];
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };

int main() {
	FASTIO;

	int N, M;
	cin >> N >> M;
	vector<string> graph(N);

	for (int i = 0; i < N; i++)
		cin >> graph[i];

	queue<tuple<int, int, int>> Q;
	Q.push({ 0,0,0 });
	dist[0][0][0] = dist[1][0][0] = 1;
	
	
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cl = get<0>(cur), cr = get<1>(cur), cc = get<2>(cur);
		if (cr == N - 1 && cc == M - 1) {
			cout << dist[cl][cr][cc] << endl;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nl = cl, nr = cr + dir[i][0], nc = cc + dir[i][1];
			
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

			if (graph[nr][nc] == '1') {
				if (nl) continue;
				else nl++;
			}

			if (!dist[nl][nr][nc]) {
				dist[nl][nr][nc] = dist[cl][cr][cc] + 1;
				Q.push({ nl,nr,nc });
			}
		}
	}

	cout << -1 << endl;
}