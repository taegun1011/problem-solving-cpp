#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define MAX 1000
#define INF 1e9

vector<PII> graph[MAX + 1];
vector<int> res;
vector<int> dist(MAX + 1, INF);
vector<int> parent(MAX + 1);

void dijkstra(int S, int E) {

	//비용, 목적지
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	dist[S] = 0;
	pq.push({ 0, S });

	int u, w;
	while (!pq.empty()) {
		w = pq.top().first;
		u = pq.top().second;
		pq.pop();

		if (dist[u] != w) continue;

		if (u == E) {
			int cur = E;
			stack<int> SS;
			while (cur != S) {
				SS.push(cur);
				cur = parent[cur];
			}

			res.push_back(S);
			while (!SS.empty()) {
				res.push_back(SS.top());
				SS.pop();
			}

			return;
		}

		for (auto next : graph[u]) {
			int v = next.first;
			int uv = next.second;

			if (dist[v] > w + uv) {
				dist[v] = w + uv;
				pq.push({ dist[v], v });
				parent[v] = u;
			}
		}
	}
}

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;

	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	int S, E;
	cin >> S >> E;

	dijkstra(S, E);

	cout << dist[E] << '\n';
	cout << res.size() << '\n';
	for (int i : res)
		cout << i << ' ';
	cout << '\n';
}

//dijkstra의 역추적은 parent 배열을 사용한다