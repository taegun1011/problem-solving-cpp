#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define edge pair<int, PII>

int N;
vector<vector<int>> c;

void solve() {
	//ÇÁ¸²
	cin >> N;
	c = vector<vector<int>>(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		cin >> c[0][i];
		c[i][0] = c[0][i];
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> c[i][j];

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ 0, 0 });

	int cnt = 0, sum = 0;
	vector<bool> visited(N + 1);
	while (cnt <= N) {
		auto p = pq.top();
		pq.pop();

		int u = p.second, w = p.first;
		if (visited[u])
			continue;

		cnt++;
		sum += w;
		visited[u] = true;

		for (int v = 0; v <= N; v++)
			pq.push({ c[u][v], v });
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}