#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e12
#define ll long long

bool compare(pair<PII, int> a, pair<PII, int> b) {
	return a.first == b.first;
}

void solve() {
	int N, M;
	cin >> N >> M;

	vector<ll> dist(N, INF);
	dist[0] = 0;

	vector<pair<PII, int>> Edges;
	int u, v, w;
	while (M--) {
		cin >> u >> v >> w;
		Edges.push_back({ {u - 1, v - 1},w });
	}
	sort(Edges.begin(), Edges.end());
	Edges.erase(unique(Edges.begin(), Edges.end(), compare),Edges.end());

	for (int i = 0; i < N - 1; i++) {
		for (auto e : Edges) {
			int u = e.first.first;
			if (dist[u] == INF)
				continue;
			int v = e.first.second;
			int w = e.second;
			dist[v] = min(dist[v], dist[u] + w);
		}
	}

	bool flag = 0;
	for (auto e : Edges) {
		int u = e.first.first;
		if (dist[u] == INF)
			continue;

		int v = e.first.second;
		int w = e.second;
		if (dist[v] > dist[u] + w) {
				flag = 1;
				break;
		}
	}

	if (flag)
		cout << -1 << endl;
	else
		for (int i = 1; i < N; i++)
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}