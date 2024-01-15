#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101];
int visited[101];

int BFS(int start, int end);

int main() {
	int V;
	cin >> V;
	int start, end;
	cin >> start >> end;

	int E, u, v;
	cin >> E;
	while (E > 0) {
		E--;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << BFS(start, end) << endl;
}

int BFS(int start, int end) {
	queue<int> Q;
	Q.push(start);

	int cur;
	while (!Q.empty()) {
		cur = Q.front(); Q.pop();

		for (auto next : graph[cur]) {
			if (!visited[next]) {
				visited[next] = visited[cur] + 1;
				if (next == end)
					return visited[next];

				Q.push(next);
			}
		}
	}
	return -1;
}