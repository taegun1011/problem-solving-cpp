#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;
vector<vector<PII>> graph;

void dijkstra(int s) {
	vector<int> dist(N, INF);
	vector<int> par(N);

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ dist[s] = 0, s });

	while (!pq.empty()) {
		PII cur = pq.top();
		pq.pop();

		int w = cur.first, u = cur.second;
		if (dist[u] != w)
			continue;

		for (PII nxt : graph[u]) {
			int uv = nxt.first, v = nxt.second;
			if (dist[v] > uv + w) {
				par[v] = u == s ? v : par[u];
				
				pq.push({ dist[v] = uv + w, v });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i == s)
			cout << '-';
		else
			cout << par[i] + 1;
		cout << ' ';
	}
	cout << '\n';
}

void solve() {
	cin >> N >> M;

	graph = vector<vector<PII>>(N, vector<PII>());

	int u, v, w;
	while (M--) {
		cin >> u >> v >> w;
		graph[u - 1].push_back({ w, v - 1 });
		graph[v - 1].push_back({ w, u - 1 });
	}

	for (int i = 0; i < N; i++)
		dijkstra(i);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}