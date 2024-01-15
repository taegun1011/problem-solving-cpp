#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> in_deg(1001);
vector<int> out[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int K;
	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> K;
		cin >> u;
		for (int j = 0; j < K - 1; j++) {
			cin >> v;

			in_deg[v]++;
			out[u].push_back(v);

			u = v;
		}
	}

	queue<int> Q;

	for (int i = 1; i <= N; i++)
		if (!in_deg[i])
			Q.push(i);

	vector<int> res;

	while (!Q.empty()) {
		int cur = Q.front();
		res.push_back(cur);
		Q.pop();

		for (int nxt : out[cur]) {
			in_deg[nxt]--;
			if (in_deg[nxt] <= 0)
				Q.push(nxt);
		}
	}

	if (res.size() == N)
		for (int i : res)
			cout << i << '\n';
	else
		cout << 0 << '\n';

	return 0;
}

//위상정렬 Kahn 알고리즘
//in-degree, out 그래프만 사용
//queue를 사용