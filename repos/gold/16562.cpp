#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, K;

vector<int> p;
vector<int> cost;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
	cost[x] = min(cost[x], cost[y]);
}

void solve() {
	cin >> N >> M >> K;

	p = vector<int>(N);
	cost = vector<int>(N);
	for (int i = 0; i < N; i++) {
		p[i] = i;
		cin >> cost[i];
	}

	int u, v;
	while (M--) {
		cin >> u >> v;
		merge(u - 1, v - 1);
	}

	int sum = 0;
	vector<bool> visited(N);
	for (int i = 0; i < N; i++) {
		int root = find(i);
		if (visited[root])
			continue;
		visited[root] = true;
		sum += cost[root];
	}

	cout << (sum <= K ? to_string(sum) : "Oh no") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}