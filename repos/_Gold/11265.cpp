#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define PII pair<int, int>

vector<vector<int>> graph;
int N;

vector<int> dijkstra(int cur) {
	vector<int> dist(N, INF);

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ (dist[cur] = 0), cur });

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		int w = cur.first, u = cur.second;
		if (dist[u] != w)
			continue;

		for (int v = 0; v < N; v++) {
			int uv = graph[u][v];
			if (dist[v] > w + uv)
				pq.push({ (dist[v] = w + uv), v });
		}
	}

	return dist;
}

void solve() {
	int M;
	cin >> N >> M;

	graph = vector<vector<int>>(N, vector<int>(N));
	for (auto& row : graph)
		for (int& x : row)
			cin >> x;

	vector<vector<int>> dist(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		dist[i] = dijkstra(i);

	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << (dist[a - 1][b - 1] <= c ? "Enjoy other party" : "Stay here") << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}