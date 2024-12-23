#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
short dir[4][2] = { -1,0,0,1,1,0,0,-1 };
int N;

void BFS_No(vector<vector<int>>& graph, vector<vector<int>>& number, int sr, int sc, int k) {
	queue<pair<int, int>> Q;
	Q.push({ sr,sc });
	number[sr][sc] = k;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			if (graph[nr][nc] == 1 && !number[nr][nc]) {
				number[nr][nc] = k;
				Q.push({ nr,nc });
			}
		}
	}
}

int BFS_dist(vector<vector<int>>& graph, vector<vector<int>>& number, int sr, int sc) {
	queue<pair<int, int>> Q;
	vector<vector<int>> dist(N, vector<int>(N));

	Q.push({ sr,sc });
	dist[sr][sc] = 1;

	int start = number[sr][sc], ret = INT_MAX;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		int cr = cur.first, cc = cur.second;

		for (int i = 0; i < 4; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			if (graph[cr][cc]) {
				if (graph[nr][nc]) { // 1->1
					if (dist[nr][nc]) continue;
					dist[nr][nc] = 1;
					Q.push({ nr,nc });
				}
				else { //1->0
					if (dist[nr][nc] == 2) continue;
					dist[nr][nc] = 2;
					Q.push({ nr,nc });
				}
			}
			else {
				if (graph[nr][nc]) { //0->1
					if (number[nr][nc] == start) continue;
					dist[nr][nc] = dist[cr][cc];
					ret = min(ret, dist[nr][nc]);
				}
				else { //0->0
					if (dist[nr][nc] && dist[nr][nc] <= dist[cr][cc] + 1) continue;
					dist[nr][nc] = dist[cr][cc] + 1;
					Q.push({ nr, nc });
				}
			}
		}
	}

	return ret - 1;
}

int main() {
	FASTIO;
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N));
	vector<vector<int>> number(N, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	vector<pair<int, int>> P;

	//섬마다 번호 지정
	int k = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (graph[i][j] && !number[i][j]) {
				P.push_back({ i,j });
					
				BFS_No(graph, number, i, j, ++k);
			}

	//각 섬에서 BFS 통해 다른 섬까지의 거리 최솟값 비교
	int ans = INT_MAX;
	for (auto p : P) 
		ans = min(ans, BFS_dist(graph, number, p.first, p.second));

	cout << ans << endl;
}