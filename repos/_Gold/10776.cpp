#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 2000
#define INF 1e9
#define PII pair<int, int>

//목적지, 비용, 감소량
vector<vector<tuple<int, int, int>>> graph(MAX + 1);

//dist[i] : i번째 지점까지 도착했을 때 시간과 뗏목 두께
vector<vector<int>> dist(MAX + 1, vector<int>(201, INF));

//매번 경로 갱신마다 뗏목의 두께가 0이 되면 무시해야함
int dijkstra(int S, int E, int K) {

	//비용, 남은 두께, 목적지
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.emplace(0, K, S);
	dist[S][K] = 0;

	int u, w, left;
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		w = get<0>(t); left = get<1>(t); u = get<2>(t);

		if (dist[u][left] != w) continue;

		for (auto next : graph[u]) {
			int v = get<0>(next); int uv = get<1>(next); int next_left = left - get<2>(next);

			if (next_left > 0 && dist[v][next_left] > w + uv) {
				dist[v][next_left] = w + uv;
				pq.emplace(dist[v][next_left], next_left, v);
			}
		}
	}

	int ret = INF;
	for (int i = 1; i <= K; i++)
		ret = min(ret, dist[E][i]);

	return (ret == INF ? -1 : ret);
}

int main() {
	FASTIO;

	int K, N, M;
	cin >> K >> N >> M;

	int u, v, w, h;
	while (M--) {
		cin >> u >> v >> w >> h;
		graph[u].push_back(tie(v, w, h));
		graph[v].push_back(tie(u, w, h));
	}

	int S, E;
	cin >> S >> E;

	cout << dijkstra(S, E, K) << '\n';
}