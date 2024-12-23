#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PDI pair<double, int>

double getDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double prim(vector<vector<PDI>>& Edges) {
	int N = Edges.size();
	vector<bool> visited(N);
	priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
	pq.push({ 0.0, 0 });

	int cnt = 0;
	double ret = 0;
	while (cnt < N) {
		PDI cur = pq.top();
		pq.pop();
		if (!visited[cur.second]) {
			visited[cur.second] = true;
			ret += cur.first;
			cnt++;

			for (const PDI &nxt : Edges[cur.second])
				pq.push(nxt);
		}
	}

	return ret;
}

void solve() {
	int N;
	cin >> N;
	vector<double> X, Y;
	double xi, yi;
	for (int i = 0; i < N; i++) {
		cin >> xi >> yi;
		X.push_back(xi);
		Y.push_back(yi);
	}

	vector<vector<PDI>> Edges(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (i != j)
				Edges[i].push_back(make_pair(getDistance(X[i], Y[i], X[j], Y[j]), j));


	cout << prim(Edges) << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}