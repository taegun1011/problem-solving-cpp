#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define edge pair<int, pair<int, int>>

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

void solve() {
	//ũ�罺Į

	int N, M;
	cin >> N >> M;
	
	p = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		p[i] = i;

	int u, v, w;
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	ll total = 0, sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		total += w;
		pq.push({ w, {u,v} });
	}

	int cnt = 0;
	while (cnt < N - 1 && !pq.empty()) {
		edge e = pq.top();
		pq.pop();

		u = e.second.first;
		v = e.second.second;

		if (find(u) == find(v))
			continue;

		cnt++;
		sum += e.first;
		merge(u, v);
	}

	cout << (cnt == N - 1 ? total - sum : -1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}