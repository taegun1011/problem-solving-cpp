#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, Q;

vector<vector<int>> graph;

void bfs(int s) {
  vector<int> dist(N + 1, -1);
  dist[s] = 0;

  queue<int> Q;
  Q.push(s);

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int nxt : graph[cur]) {
      if (dist[nxt] == -1 || dist[nxt] > dist[cur] + 1) {
        dist[nxt] = dist[cur] + 1;
        Q.push({nxt});
      }
    }
  }

  for (int i = 1; i <= N; i++) cout << dist[i] << ' ';
  cout << endl;
}

void solve() {
  cin >> N >> M;
  graph = vector<vector<int>>(N + 1, vector<int>());

  int u, v;
  while (M--) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cin >> Q;
  while (Q--) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    bfs(1);
  }
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}