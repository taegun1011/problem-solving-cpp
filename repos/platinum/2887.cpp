#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define PII pair<int, int>
#define Edge pair<int, PII>

vector<int> p;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
}

ll kruskal(int V, vector<Edge> Edges) {
	sort(Edges.begin(), Edges.end());

	int E = Edges.size();
	p.resize(V);
	for (int i = 0; i < V; i++)
		p[i] = i;

	ll sum = 0;
	int cnt = 0;

	for (int i = 0; i < E; i++) {
		Edge cur = Edges[i];
		int u = cur.second.first, v = cur.second.second, w = cur.first;
		if (find(u) != find(v)) {
			cnt++;
			sum += w;
			merge(u, v);
		}

		if (cnt == V - 1)
			break;
	}

	return sum;
}


void solve() {
	int N;
	cin >> N;

	//coord, idx
	vector<PII> X, Y, Z;
	vector<PII> coord[3];

	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num;
			coord[j].push_back({ num,i });
		}
	}
	for (int i = 0; i < 3; i++)
		sort(coord[i].begin(), coord[i].end());

	vector<Edge> Edges;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N - 1; j++) {
			PII cur = coord[i][j], nxt = coord[i][j + 1];
			Edges.push_back({ nxt.first - cur.first, {cur.second, nxt.second} });
		}
	}

	cout << kruskal(N, Edges) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}