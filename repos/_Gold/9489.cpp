#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


vector<vector<int>> graph;
vector<vector<int>> level_node;

void traverse(int cur, int lv, int k_par) {
	if (cur == 0)
		level_node = vector<vector<int>>(1001, vector<int>());

	if (cur == k_par)
		return;
	level_node[lv].push_back(cur);

	for (int nxt : graph[cur])
		traverse(nxt, lv + 1, k_par);
}

int find_level(int cur, int lv, int k) {
	if (cur == k)
		return lv;
	int ret = -1;
	for (int nxt : graph[cur])
		ret = max(ret, find_level(nxt, lv + 1, k));
	return ret;
}
void solve() {
	int N, K;
	cin >> N >> K;
	while (!(N == 0 && K == 0)) {
		vector<int> idx(1000001);
		int n_idx = 1;

		graph = vector<vector<int>>(1001, vector<int>());
		vector<int> par(1001);
		queue<int> Q;
		int rt = 0, prv = -1;

		for (int i = 0; i < N; i++) {
			int cur;
			cin >> cur;

			int c_idx = idx[cur] = n_idx++;

			if (cur > prv + 1 && !Q.empty()) {
				rt = idx[Q.front()];
				Q.pop();
			}

			graph[rt].push_back(c_idx);
			par[c_idx] = rt;

			Q.push(cur);
			prv = cur;
		}

		int pp = idx[K], ans = 0;
		pp = par[pp];
		if (par[pp] != 0) {
			pp = par[pp];
			for (int p : graph[pp])
				ans += graph[p].size();
			ans -= graph[par[idx[K]]].size();
		}
		cout << ans << '\n';

		cin >> N >> K;
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}