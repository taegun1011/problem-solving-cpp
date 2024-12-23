#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int** graph;
int* visited;
int n, m;

void DFS(int i);

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	graph = new int* [n];
	visited = new int [n];

	for (int i = 0; i < n; i++) {
		graph[i] = new int[n];
		visited[i] = 0;
		for (int j = 0; j < n; j++)
			graph[i][j] = 0;
	}

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			count++;
			DFS(i);
		}
	}

	cout << count << endl;
}

void DFS(int i) {
	visited[i] = 1;
	for (int j = 0; j < n; j++) {
		if (graph[i][j] == 1)
			if(!visited[j])
				DFS(j);
	}
}