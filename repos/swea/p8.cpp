#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 8 [S/W 문제해결 응용] 3일차 - 공통조상

vector<vector<int>> graph;

int get_size(int cur, int prv) {
	int ret = 1;
	for (int nxt : graph[cur]) {
		if (nxt == prv)
			continue;
		ret += get_size(nxt, cur);
	}
	return ret;
}

void solve(int tc) {
	int V, E, a, b;
	cin >> V >> E >> a >> b;

	graph = vector<vector<int>>(V + 1, vector<int>());
	vector<int> parent(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		parent[v] = u;
	}

	vector<bool> visited(V + 1);
	while (a) {
		visited[a] = 1;
		a = parent[a];
	}

	while (!visited[b])
		b = parent[b];

	int lca = b;
	printf("#%d %d %d\n", tc, lca, get_size(lca, parent[lca]));
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
		solve(tc);

}