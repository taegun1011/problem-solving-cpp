#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int PGG;

int find(vector<vector<PII>>& graph, int cur, int prv) {
	int cnt = 0;
	int nxt = 0;
	for (PII p : graph[cur])
		if (p.first != prv) {
			cnt++;
			nxt = p.first;
		}

	if (cnt != 1) {
		PGG = prv;
		return cur;
	}

	return find(graph, nxt, cur);
}

int getHeight(vector<vector<PII>>& graph, int cur, int prv) {
	int ret = 0;

	for (PII p : graph[cur])
		if (p.first != prv)
			ret = max(ret, getHeight(graph, p.first, cur) + p.second);

	return ret;
}

void solve() {
	int N, R;
	cin >> N >> R;
	int M = N - 1;

	vector<vector<PII>> graph(N + 1, vector<PII>());
	while (M--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	//기가 노드 찾기
	int GG = find(graph, R, 0);

	//기가부터 높이
	int a = getHeight(graph, GG, PGG);

	//루트부터 높이
	int b = getHeight(graph, R, 0);

	cout << b - a << ' ' << a << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}