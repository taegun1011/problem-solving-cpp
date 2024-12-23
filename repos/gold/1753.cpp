#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define INF 1e9
#define MAX 20000

vector<PII> graph[MAX + 1];
vector<int> dist(MAX + 1, INF);

int V, E;

void dijkstra(int start) {
	//비용, 노드 순으로 저장한다
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	//초기화
	dist[start] = 0;
	pq.push({ 0, start });

	int w, u;
	while (!pq.empty()) {
		//pq에서 비용이 가장 낮은 원소를 꺼낸다
		w = pq.top().first;
		u = pq.top().second;
		pq.pop();

		if (dist[u] != w) continue;

		for (auto next : graph[u]) {
			int v = next.first, uv = next.second;

			//현재 노드를 경유할 때 거리 갱신이 된다면
			//거리를 갱신하고 큐에 넣는다
			if (w + uv < dist[v]) {
				dist[v] = w + uv;
				pq.push({ w + uv, v });
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> V >> E;

	int K; cin >> K;

	int u, v, w;

	//중복 포함한 간선 입력
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;

		graph[u].emplace_back(v, w);
	}

	dijkstra(K);
	for (int i = 1; i <= V; i++)
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
}

//다이스트라 복습 (pq 사용 버전)
//pq : <비용, 목적지>
//pq 사용할 경우, visited 필요없고 최소비용만 저장할 필요 없음
//최단 거리 갱신이 완료되면 알아서 pq가 비기 때문