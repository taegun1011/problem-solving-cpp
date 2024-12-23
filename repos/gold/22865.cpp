#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define PII pair<int, int>

vector<vector<PII>> graph;
vector<int>	result;
int N;

void dijkstra(int start) {
	vector<int> dist(N, INF);

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ dist[start] = 0, start });

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		int u = cur.second, w = cur.first;
		if (dist[u] != w)
			continue;

		for (PII nxt : graph[u]) {
			int v = nxt.first, uv = nxt.second;
			if (dist[v] > w + uv)
				pq.push({ dist[v] = w + uv, v });
		}
	}

	for (int i = 0; i < N; i++)
		result[i] = min(result[i], dist[i]);
}

void solve() {
	int M, a, b, c;
	cin >> N >> a >> b >> c;

	result = vector<int>(N, INF);
	graph = vector<vector<PII>>(N, vector<PII>());
	cin >> M;
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;

		graph[u - 1].push_back({ v - 1, w });
		graph[v - 1].push_back({ u - 1, w });
	}

	dijkstra(--a);
	dijkstra(--b);
	dijkstra(--c);

	PII ans = { 0, 0 };
	for (int i = 0; i < N; i++)
		ans = max(ans, { result[i], -i });
	
	cout << -ans.second + 1 << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}