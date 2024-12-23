#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define INF 1e9
vector<int> dist(100001, INF);

bool inRange(int num) {
	return 0 <= num && num <= 100000;
}

int dijkstra(int N, int K) {

	//비용, 목적지
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ dist[N] = 0, N });

	int u, w, v;
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();

		w = t.first; u = t.second;
		if (w != dist[u]) continue;

		if (u == K)
			return w;
		v = u - 1;

		if (inRange(v) && dist[v] > w + 1) {
			dist[v] = w + 1;
			pq.push({ dist[v], v });
		}

		v = u + 1;

		if (inRange(v) && dist[v] > w + 1) {
			dist[v] = w + 1;
			pq.push({ dist[v], v });
		}

		v = u * 2;

		if (inRange(v) && dist[v] > w) {
			dist[v] = w;
			pq.push({ dist[v], v });
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << dijkstra(N, K) << endl;
}