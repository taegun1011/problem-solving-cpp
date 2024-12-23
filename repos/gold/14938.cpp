#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9

void solve() {
	int n, m, r;
	cin >> n >> m >> r;

	vector<int> item(n);
	for (int& x : item)
		cin >> x;

	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	while (r--) {
		int u, v, w;
		cin >> u >> v >> w;
		dist[u - 1][v - 1] = dist[v - 1][u - 1] = w;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (dist[i][j] <= m)
				sum += item[j];
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}