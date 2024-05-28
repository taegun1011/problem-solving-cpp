#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
	//ÇÁ¸²
	int N, M, u, v, w;
	cin >> N >> M;
	vector<bool> visited(N);

	vector<vector<PII>> graph(N, vector<PII>());
	while (M--) {
		cin >> u >> v >> w;
		if (u == v)
			continue;
		graph[u - 1].push_back({ w, v - 1 });
		graph[v - 1].push_back({ w, u - 1 });
	}

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ 0, 0 });
	int cnt = 0;
	ll sum = 0;
	while (cnt < N && !pq.empty()) {
		PII p = pq.top();
		pq.pop();

		int w = p.first, u = p.second;

		if (visited[u])
			continue;

		visited[u] = 1;
		cnt++;
		sum += w;

		for (PII p : graph[u])
			pq.push(p);
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}