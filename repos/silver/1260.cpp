#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];

bool Dvisited[1001];
bool Bvisited[1001];

void DFS(int node) {
	Dvisited[node] = 1;
	cout << node << ' ';

	for (int i : graph[node])
		if (!Dvisited[i])
			DFS(i);
}

void BFS(int node) {
	queue<int> Q;
	Q.push(node);
	Bvisited[node] = 1;
	cout << node << ' ';

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();
		for(int next : graph[cur])
			if (!Bvisited[next]) {
				Bvisited[next] = 1;
				cout << next << ' ';
				Q.push(next);
			}
	}
}

int main() {
	int V, E, start;
	cin >> V >> E >> start;

	int u, v;
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= V; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(start);
	cout << '\n';
	BFS(start);
	cout << '\n';
}