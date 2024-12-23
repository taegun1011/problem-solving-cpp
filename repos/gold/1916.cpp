#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define INF 1e9

int N, M;

vector<vector<PII>> graph;

bool compare(PII a, PII b) { return a.first == b.first; }

int dijkstra(int s, int e) {
  vector<int> dist(N + 1, INF);

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({dist[s] = 0, s});

  while (!pq.empty()) {
    PII cur = pq.top();
    pq.pop();

    int u = cur.second, w = cur.first;
    if (dist[u] < w) continue;

    for (PII nxt : graph[u]) {
      int v = nxt.first, uv = nxt.second;
      if (dist[v] > uv + w) pq.push({dist[v] = uv + w, v});
    }
  }

  return dist[e];
}

void solve() {
  cin >> N >> M;
  graph = vector<vector<PII>>(N + 1, vector<PII>());

  int u, v, w;
  while (M--) {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
    graph[i].erase(unique(graph[i].begin(), graph[i].end(), compare),
                   graph[i].end());
  }

  cin >> u >> v;
  cout << dijkstra(u, v) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}