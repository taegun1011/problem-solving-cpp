#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M;

#define PII pair<int, int>
#define PIP pair<int, PII>
#define INF 987654321

int dir[8][2] = { -1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1 };

//지도, 시작점 좌표들, 좌우 상하 범위, 도착점
int dijkstra(vector<vector<int>>& map, vector<PII>& start, int l, int r, int u, int d, int er, int ec) {

	vector<vector<int>> dist(N + 2, vector<int>(M + 2, INF));

	priority_queue<PIP, vector<PIP>, greater<PIP>> pq;
	for (PII p : start) {
		int sr = p.first, sc = p.second;
		pq.push({ (dist[sr][sc] = 0), { sr, sc } });
	}

	while (!pq.empty()) {
		PIP p = pq.top();
		pq.pop();

		int cr = p.second.first, cc = p.second.second, cd = p.first;
		if (cr == er && cc == ec)
			return cd;
		if (cd != dist[cr][cc])
			continue;

		for (int i = 0; i < 8; i++) {
			int nr = cr + dir[i][0];
			int nc = cc + dir[i][1];

			if (nr < u || nr > d || nc < l || nc > r)
				continue;
			int nd = cd + 1 - map[nr][nc];
			if (dist[nr][nc] > nd)
				pq.push({ (dist[nr][nc] = nd), {nr, nc} });
		}
	}

	return INF;
}

void solve() {
	cin >> N >> M;

	//능력 부족,, 1은 별도 처리
	if (N == 1 || M == 1) {
		int x;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				cin >> x;
				if (x == 1) {
					cout << 0 << endl;
					return;
				}
			}
		cout << 1 << endl;
		return;
	}

	vector<vector<int>> map(N + 2, vector<int>(M + 2));
	vector<PII> lstart, rstart, ustart, dstart;
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			if (!i || i == N + 1 || !j || j == M + 1) {
				map[i][j] = 1;
				continue;
			}
			else
				cin >> map[i][j];
			if (map[i][j] == 1) {
				if (i == 1)
					ustart.push_back({ i,j });
				else if (i == N)
					dstart.push_back({ i, j });
				else if (j == 1)
					lstart.push_back({ i,j });
				else if (j == M)
					rstart.push_back({ i,j });
			}
		}
	}

	int ans = 2;
	//왼쪽 -> 오른쪽
	ans = min(ans, dijkstra(map, lstart, 1, M+1, 1, N, N, M + 1));
	
	//위 -> 아래
	ans = min(ans, dijkstra(map, ustart, 1, M, 1, N+1, N+1, M));

	//왼쪽 -> 위
	ans = min(ans, dijkstra(map, lstart, 1, M, 0, N, 0, M));

	//위 -> 왼쪽
	ans = min(ans, dijkstra(map, ustart, 0, M, 1, N, N, 0));
	
	//오른쪽 -> 아래
	ans = min(ans, dijkstra(map, rstart, 1, M, 1, N+1, N+1, M));

	//아래 -> 오른쪽
	ans = min(ans, dijkstra(map, dstart, 1, M+1, 1, N, 1, M + 1));
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