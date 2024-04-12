#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> graph;
vector<bool> visited;

int find_child(int cur) {
	visited[cur] = true;

	int ret = 0;
	for (int nxt : graph[cur])
		if (!visited[nxt])
			ret += find_child(nxt);


	return ret ? ret : 1;
}

void solve() {
	int N, W;
	cin >> N >> W;
	
	graph = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1);
	while (N-- - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printf("%lf\n", 1.0 * W / find_child(1));
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}