#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
	//ÇÁ¸²
	int N;
	cin >> N;
	vector<bool> visited(N);

	vector<vector<int>> arr(N, vector<int>(N));
	for (auto& row : arr)
		for (int& x : row)
			cin >> x;

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({ 0, 0 });
	int cnt = 0;
	ll sum = 0;
	while (cnt < N && !pq.empty()) {
		PII p = pq.top();
		pq.pop();

		int w = p.first, u = p.second;

		if (visited[u])
			continue;

		visited[u] = 1;
		cnt++;
		sum += w;

		for (int v = 0; v < N; v++) {
			if (v == u)
				continue;
			pq.push({ arr[u][v], v });
		}
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