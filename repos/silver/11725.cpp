#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> graph[100001];
int parent[100001];
int visited[100001];
int N;

void BFS(int node) {
	queue<int> Q;
	Q.push(node);
	visited[node] = 1;

	int cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();
		visited[cur] = 1;

		for (int next : graph[cur])
			if (!visited[next]) {
				parent[next] = cur;
				Q.push(next);
			}
				

	}
}

int main() {
	FASTIO;
	cin >> N;
	
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	BFS(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}