#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define PDI pair<double, int>

vector<int> x, y;
vector<vector<double>> graph;
int N;
double M;

double get_distance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

vector<double> dijkstra(int start) {
	vector<double> dist(N, INF);
	
	priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
	pq.push({ (dist[start] = 0), start });

	while (!pq.empty()) {
		PDI cur = pq.top();
		pq.pop();

		double w = cur.first;
		int u = cur.second;

		if (dist[u] != w)
			continue;

		for (int v = 0; v < N; v++) {
			double uv = graph[u][v];
			if (uv > M)
				continue;
			if (dist[v] > w + uv)
				pq.push({ (dist[v] = w + uv), v });
		}
	}

	return dist;
}

void solve() {
	int W;
	cin >> N >> W;
	cin >> M;

	x = vector<int>(N);
	y = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];
	graph = vector<vector<double>>(N, vector<double>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			graph[i][j] = get_distance(x[i], y[i], x[j], y[j]);

	while (W--) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = graph[b - 1][a - 1] = 0;
	}

	double ans = dijkstra(0)[N - 1];
	cout << (ans < 0 ? -1 : (long)floor(ans * 1000)) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}