#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M;
vector<int> p;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	p[y] = x;
}

int kruskal(vector<pair<int, pair<int, int>>>& Edges, vector<char>& gender) {
	sort(Edges.begin(), Edges.end());

	int sum = 0, cnt = 0;
	for (const auto& e : Edges) {
		int u = e.second.first, v = e.second.second, w = e.first;
		if (gender[u] == gender[v])
			continue;
		if (find(u) == find(v))
			continue;
		sum += w;
		cnt++;
		merge(u, v);
	}

	return cnt == N - 1 ? sum : -1;
}

void solve() {
	cin >> N >> M;

	vector<char> gender(N);
	p = vector<int> (N);
	for (int i = 0; i < N; i++)
		p[i] = i;

	for (char& ch : gender)
		cin >> ch;

	vector<pair<int, pair<int, int>>> Edges;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		Edges.push_back({ w, {u - 1, v - 1} });
	}

	cout << kruskal(Edges, gender) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}