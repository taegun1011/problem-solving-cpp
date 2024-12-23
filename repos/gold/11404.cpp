#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int V, E;
vector<vector<int>> graph(101, vector<int>(101));
void floyd();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;
	int temp = E, u, v, weight;

	int i, j;

	for (i = 1; i <= V; i++)
		for (j = 1; j <= V; j++)
			graph[i][j] = (i == j ? 0 : INF);

	while (temp > 0) {
		temp--;
		cin >> u >> v >> weight;
		if (graph[u][v] > weight)
			graph[u][v] = weight;
	}

	floyd();

	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) {
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		}
		cout << '\n';
	}
}

void floyd() {
	int i, j, k;

	for (k = 1; k <= V; k++) {
		for (i = 1; i <= V; i++) {
			for (j = 1; j <= V; j++) {
				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}