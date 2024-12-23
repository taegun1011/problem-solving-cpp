#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int cnt = 1;

void DFS(int cur, vector<vector<int>>& graph, vector<int>& dist) {
	dist[cur - 1] = cnt;
	for (int nxt : graph[cur])
		if (!dist[nxt - 1]) {
			cnt++;
			DFS(nxt, graph, dist);
		}
}

int main() {
	FASTIO;

	int N, M, R;
	cin >> N >> M >> R;
	vector<vector<int>> graph(N + 1, vector<int>());
	vector<int> dist(N);

	while (M--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (auto& v : graph)
		sort(v.begin(), v.end());

	DFS(R, graph, dist);
	for (int x : dist)
		cout << x << '\n';
}