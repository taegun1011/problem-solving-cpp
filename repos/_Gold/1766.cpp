#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, M;
	cin >> N >> M;

	vector<int> in(N + 1);
	vector<vector<int>> graph(N + 1, vector<int>());

	int a, b;
	while (M--) {
		cin >> a >> b;
		in[b]++;
		graph[a].push_back(b);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
		if (!in[i])
			pq.push(i);
	
	//항상 답이 존재
	while (!pq.empty()) {
		int cur = pq.top();
		cout << cur << ' ';
		pq.pop();

		for (int nxt : graph[cur])
			if (!(--in[nxt]))
				pq.push(nxt);
	}

	cout << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}