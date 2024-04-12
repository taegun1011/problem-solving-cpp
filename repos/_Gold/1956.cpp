#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9

void solve() {
	int V, E;
	cin >> V >> E;

	vector<vector<int>> dist(V, vector<int>(V, INF));

	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;

		dist[a - 1][b - 1] = c;
	}

	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = INF;
	for (int i = 0; i < V; i++)
		ans = min(ans, dist[i][i]);

	cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}