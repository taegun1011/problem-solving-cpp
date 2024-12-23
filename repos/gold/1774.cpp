#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PDI pair<double, int>

//정점 1000, 간선 500000
double prim(vector<vector<int>>& graph, vector<vector<double>>& dist) {
	int N = graph.size();
	vector<bool> visited(N);

	priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
	pq.push({ 0, 0 });

	int cnt = 0;
	double sum = 0;
	while (cnt < N) {
		PDI cur = pq.top();
		pq.pop();

		double w = cur.first;
		int v = cur.second;

		if (visited[v])
			continue;

		visited[v] = true;
		sum += w;
		cnt++;

		for (int nxt : graph[v])
			if (!visited[nxt])
				pq.push({ 0, nxt });
		for (int nxt = 0; nxt < N; nxt++)
			if (!visited[nxt])
				pq.push({ dist[v][nxt], nxt });
	}

	return sum;
}

double getDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve() {
	int N, M;
	cin >> N >> M;

	vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++)
		cin >> X[i] >> Y[i];

	vector<vector<double>> dist(N, vector<double>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = getDistance(X[i], Y[i], X[j], Y[j]);

	vector<vector<int>> graph(N, vector<int>());
	int a, b;
	while (M--) {
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	printf("%.2f\n", prim(graph, dist));
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}