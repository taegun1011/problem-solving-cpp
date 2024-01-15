#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<tuple<int, int, int>> edge;
int root[10001];
int level[10001];

int V, E;

int find(int i) {
	if (i == root[i])
		return i;
	else
		return root[i] = find(root[i]);
}

void uni(int x, int y) {
	int xRoot = find(x), yRoot = find(y);

	if (level[xRoot] > level[yRoot])
		root[yRoot] = root[xRoot];
	else if (level[yRoot] > level[xRoot])
		root[xRoot] = root[yRoot];
	else {
		root[yRoot] = root[xRoot];
		level[xRoot]++;
	}
}

void solve() {
	for (int i = 1; i <= V; i++)
		root[i] = i;

	int cnt = 0, i = 0, sum = 0;
	while (cnt < V - 1) {
		const auto& nxt = edge[i++];

		auto [w, u, v] = nxt;
		if (find(u) == find(v))
			continue;

		sum += w;
		uni(u, v);
		cnt++;
	}

	cout << sum << endl;
}

//크루스칼 알고리즘
int main() {
	FASTIO;

	cin >> V >> E;

	int u, v, w;
	while (E) {
		E--;
		cin >> u >> v >> w;
		edge.emplace_back(w, u, v);
	}

	sort(edge.begin(), edge.end());

	solve();
}

//크루스칼
//sorted edge list 사용
//union find 기법

//find : 재귀적으로 (path compression 깔즤)
//union : find로 루트 기준 병합, 작은 트리를 큰 트리에 (같으면 rank ++)