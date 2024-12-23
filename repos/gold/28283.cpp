#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define MAX 500000
#define INF 1e9
#define ll long long

int money[MAX + 1];
vector<int> sys;
vector<PII> graph[MAX + 1];
vector<int> dist(MAX + 1, INF);

bool compare(int a, int b) {
	return a > b;
}

void dijkstra() {
	//비용, 목적지
	priority_queue<PII, vector<PII>, greater<PII>> pq;

	//multi-source dijkstra
	for (int i : sys) {
		dist[i] = 0;
		pq.push({ 0, i });
	}

	int u, w;
	while (!pq.empty()) {
		w = pq.top().first;
		u = pq.top().second;
		pq.pop();

		if (dist[u] != w)
			continue;

		for (auto next : graph[u]) {
			int v = next.first;
			int uv = next.second;

			if (dist[v] > w + uv) {
				dist[v] = w + uv;
				pq.push({ dist[v], v });
			}
		}
	}
}

int main() {
	FASTIO;

	int N, M, X, Y;
	cin >> N >> M >> X >> Y;

	for (int i = 1; i <= N; i++)
		cin >> money[i];

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back({ v, 1 });
		graph[v].push_back({ u, 1 });
	}

	int node;
	for (int i = 0; i < Y; i++) {
		cin >> node;
		sys.push_back(node);
	}

	//각 컴퓨터에 보안시스템이 도달하기 전까지는 돈을 뜯을 수 있다
	dijkstra();

	//500000 * 500000 * 500000 > INT_MAX

	//벌 수 있는 모든 금액을 저장
	vector<ll> res;

	for (int i = 1; i <= N; i++) {
		//값이 INF여도 돈을 못 뜯는 컴퓨터
		if (dist[i] == INF && money[i]) {
			cout<< -1 << '\n';
			return 0;
		}
		res.push_back(1ll * dist[i] * money[i]);
	}

	sort(res.begin(), res.end(), compare);

	ll sum = 0;
	for (int i = 0; i < X; i++)
		sum += res[i];

	cout << sum << endl;
}