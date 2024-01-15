#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

void solve();
bool floyd(vector<vector<int>>& graph, int V);

int main() {
	int TC;
	cin >> TC;

	while (TC > 0) {
		TC--;
		solve();
	}
}

void solve() {
	int V, E, WH;
	cin >> V >> E >> WH;
	
	vector<vector<int>> graph(V + 1, vector<int> (V + 1));
	int u, v, w;

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			graph[i][j] = (i == j ? 0 : INF);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		if (graph[u][v] > w) {
			graph[u][v] = w;
			graph[v][u] = w;
		}
	}

	for (int i = 0; i < WH; i++) {
		cin >> u >> v >> w;
		if (graph[u][v] > -w)
			graph[u][v] = -w;
	}

	string result = (floyd(graph, V) ? "YES" : "NO");
	cout << result << endl;
}

bool floyd(vector<vector<int>>& graph, int V) {
	int i, j, k;

	for (k = 1; k <= V; k++)
		for (i = 1; i <= V; i++)
			for (j = 1; j <= V; j++) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
	for (i = 1; i <= V; i++)
		if (graph[i][i] < 0)
			return true;

	return false;
}