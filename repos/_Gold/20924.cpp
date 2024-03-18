#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int find(vector<vector<PII>>& graph, int cur, vector<bool>& visited) {
	visited[cur] = true;

	int cnt = 0;
	int nxt = 0;
	for (PII p : graph[cur])
		if (!visited[p.first]) {
			cnt++;
			nxt = p.first;
		}
	return cnt == 1 ? find(graph, nxt, visited) : cur;
}

int getHeight(vector<vector<PII>>& graph, int cur, vector<bool>& visited) {
	visited[cur] = true;
	int ret = 0;

	for (PII nxt : graph[cur])
		if(!visited[nxt.first])
			ret = max(ret, getHeight(graph, nxt.first, visited) + nxt.second);

	return ret;
}

void solve() {
	int N, R;
	cin >> N >> R;
	int M = N - 1;

	vector<vector<PII>> graph(N + 1, vector<PII>());
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	//기가 노드를 찾는다
	vector<bool> visited(N + 1);
	int GG = find(graph, R, visited);

	//기가부터 높이, visited 유지하는 게 핵심
	int a = getHeight(graph, GG, visited);

	//루트부터 높이
	visited = vector<bool>(N + 1);
	int b = getHeight(graph, R, visited);
	
	cout << b - a << ' ' << a << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}