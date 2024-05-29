#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, M, u, v;
	cin >> N >> M;

	vector<vector<bool>> graph(N, vector<bool>(N));
	while (M--) {
		cin >> u >> v;
		graph[u - 1][v - 1] = true;
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				graph[i][j] = graph[i][j] || (graph[i][k] & graph[k][j]);

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++)
			sum += graph[i][j] || graph[j][i];
		cout << N - sum - 1 << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}