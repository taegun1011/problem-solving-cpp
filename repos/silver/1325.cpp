#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void BFS(int start, vector<vector<int>>& graph, vector<int>& count) {
	queue<int> Q;
	Q.push(start);

	vector<bool> visited(count.size());
	visited[start] = true;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int nxt : graph[cur]) {
			if (!visited[nxt]) {
				count[start]++;
				visited[nxt] = true;
				Q.push(nxt);
			}
		}
	}
}

int main() {
	FASTIO;

	int N, M;
	int A, B;
	cin >> N >> M;

	vector<vector<int>> graph(N + 1, vector<int>());
	vector<int> count(N + 1);

	while (M-- > 0) {
		cin >> A >> B;
		graph[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		BFS(i, graph, count);
	}

	vector<int> res;
	int max = 0;
	for (int i = 1; i <= N;i++) {
		if (count[i] < max)
			continue;
		if (count[i] > max) {
			max = count[i];
			res.clear();
		}
		res.push_back(i);
	}

	for (int x : res)
		cout << x << ' ';
	cout << endl;
}