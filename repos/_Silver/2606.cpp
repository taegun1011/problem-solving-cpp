#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(int n, vector<vector<int>> graph);

int main() {
	int V, E;
	cin >> V;
	vector<vector<int>> graph;
	int i;
	for (i = 0; i <= V; i++) {
		vector<int> temp;
		graph.push_back(temp);
	}

	cin >> E;

	int u, v;
	for (i = 0; i < E; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << BFS(1, graph) << endl;
}

int BFS(int n, vector<vector<int>> graph) {
	int V = graph.size() - 1;
	queue<int> Q;
	int* visited = new int[V + 1];
	for (int i = 0; i <= V; i++)
		visited[i] = 0;

	Q.push(n);

	int top, count = 0;
	while (!Q.empty()) {
		top = Q.front();
		Q.pop();
		if (!visited[top]) {
			visited[top] = 1;
			count++;
			for (vector<int>::iterator iter = graph[top].begin(); iter != graph[top].end(); iter++)
				Q.push(*iter);
		}
	}

	delete[] visited;

	return count - 1;
}