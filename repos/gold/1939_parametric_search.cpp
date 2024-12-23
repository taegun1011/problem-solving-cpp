#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

vector<vector<PII>> graph;
int a, b, N;

bool check(int weight) {
	vector<bool> visited(N + 1);

	queue<int> Q;
	Q.push(a);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == b)
			return true;

		for (PII nxt : graph[cur]) {
			if (visited[nxt.first] || weight > nxt.second)
				continue;
			visited[nxt.first] = true;
			Q.push(nxt.first);
		}
	}

	return false;
}

void solve() {
	int M;
	cin >> N >> M;

	graph = vector<vector<PII>>(N + 1, vector<PII>());
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	cin >> a >> b;

	//YYYYNNNN
	int s = 0, e = 1000000000, m;
	while (s < e) {
		m = (s + e + 1) / 2;
		if (check(m))
			s = m;
		else
			e = m - 1;
	}

	cout << s << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}