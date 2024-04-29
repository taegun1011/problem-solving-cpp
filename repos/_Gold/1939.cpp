#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define Edge pair<int, pair<int, int>>

int p[10001];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	p[y] = x;
}

void solve() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;

	priority_queue<Edge> pq;
	while (M--) {
		Edge e;
		cin >> e.second.first >> e.second.second >> e.first;
		pq.push(e);
	}

	int a, b;
	cin >> a >> b;

	while (!pq.empty()) {
		auto e = pq.top();
		pq.pop();

		int u = e.second.first, v = e.second.second, w = e.first;

		if (find(u) != find(v))
			merge(u, v);

		if (find(a) == find(b)) {
			cout << w << '\n';
			break;
		}
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