#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define PII pair<int, int>

//각 간선 (u, v)에 대해
//mx := max(dist[u], dist[v]), mn := min(dist[u], dist[v])라고 하자
//mx초 후 간선의 남은 길이 left = length - (mx - mn)
//양쪽이 동시에 타기 시작할 때부터 left가 모두 탈 때까지 걸리는 시간 = left / 2 = (length + mn - mx) / 2
//양쪽이 동시에 타기 시작하는 시간 = mx
//따라서 간선 (u, v)가 완전히 타는 데 걸리는 시간은 (length + mn - mx) / 2 + mx = (length + mn + mx) / 2 = (length + dist[u] + dist[v]) / 2

void solve() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> dist(N, vector<int>(N, INF));
	for (int i = 0; i < N; i++)
		dist[i][i] = 0;

	vector<vector<int>> edges(M, vector<int>(3));
	for (auto& e : edges) {
		cin >> e[0] >> e[1] >> e[2];
		e[0]--;
		e[1]--;
		dist[e[0]][e[1]] = min(dist[e[0]][e[1]], e[2]);
		dist[e[1]][e[0]] = min(dist[e[1]][e[0]], e[2]);
	}

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	double ans = INF;
	for (int i = 0; i < N; i++) {
		double mx = 0;
		for (auto e : edges) {
			int u = e[0], v = e[1], w = e[2];
			mx = max(mx, (0.0 + dist[i][u] + dist[i][v] + w) / 2);
		}
		ans = min(ans, mx);
	}

	printf("%.1lf\n", ans);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}