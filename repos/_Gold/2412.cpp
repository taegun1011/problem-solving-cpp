#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, T;
	cin >> N >> T;


	map<int, map<int, bool>> graph;
	map<int, map<int, bool>> visited;
	while (N--) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = true;
		visited[x][y] = false;
	}

	//°Å¸®, x, y
	queue<pair<int, pair<int, int>>> Q;
	Q.push({ 0, {0,0} });

	int ans = -1;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cd = cur.first, cx = cur.second.first, cy = cur.second.second;
		if (cy == T) {
			ans = cd;
			break;
		}

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				int nx = cx + i;
				int ny = cy + j;
				if (graph[nx][ny] && !visited[nx][ny]) {
					visited[nx][ny] = true;
					Q.push({ cd + 1, { nx, ny } });
				}
			}
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