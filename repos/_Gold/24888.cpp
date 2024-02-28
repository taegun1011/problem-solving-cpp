#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define ll long long
#define PLL pair<ll, ll>
#define INF (ll)1e18

vector<ll> dijkstra(ll s, ll e, vector<vector<PLL>>& graph) {
	vector<ll> dist(graph.size(), INF);

	//가중치 - 정점
	priority_queue<PLL, vector<PLL>, greater<PLL>> pq;
	pq.push({ (dist[s] = 0), s });

	while (!pq.empty()) {
		PLL cur = pq.top();
		pq.pop();

		ll u = cur.second; ll w = cur.first;
		if (dist[u] != w)
			continue;

		for (const PLL& adj : graph[u]) {
			ll v = adj.first;
			ll uv = adj.second;
			if (dist[v] > w + uv) {
				dist[v] = w + uv;
				pq.push({ dist[v], v });
			}
		}
	}

	return dist;
}

vector<int> note;
int dp[200001];
int path[200001];

int re_dp(int cur, vector<vector<PLL>>& graph, vector<ll>& dist) {
	if (cur == 1)
		return note[cur];
	if (dp[cur] != -1)
		return dp[cur];
	int& ret = dp[cur];

	//dist[cur] - w == dist[nxt]인 간선만 선택
	for (const PLL& adj : graph[cur]) {
		ll nxt = adj.first, w = adj.second;
		if (dist[cur] - w == dist[nxt]) {
			int temp = re_dp(nxt, graph, dist);
			if (ret < temp) {
				ret = temp;
				path[cur] = nxt;
			}
		}
	}

	return (ret += note[cur]);
}

void reconstruct(int N) {
	stack<int> ans;
	int cur = N;

	while (cur != 1) {
		ans.push(cur);
		cur = path[cur];
	}

	ans.push(1);
	cout << ans.size() << '\n';
	while (!ans.empty()) {
		cout << ans.top() << (ans.size() == 1 ? '\n' : ' ');
		ans.pop();
	}
}

void solve() {
	int N, M;
	
	cin >> N >> M;
	vector<vector<PLL>> graph(N + 1, vector<PLL>());
	while (M--) {
		ll u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}

	note.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> note[i];
	int total = count(note.begin(), note.end(), 1);

	vector<ll> dist = dijkstra(1, N, graph);

	memset(dp, -1, sizeof(dp));
	int max = re_dp(N, graph, dist);
	if (max == total) {
		reconstruct(N);
	}
	else
		cout << -1 << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}