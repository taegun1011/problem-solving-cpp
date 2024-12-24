#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define Edge pair<int, PII>
#define ll long long
#define INF 1e9

int N, M;

vector<vector<int>> graph;

int p[1001];

int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = p[x];
  y = p[y];

  p[y] = x;
}

// 1을 제외한 MST
void kruskal() {
  vector<PII> ans;
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

  for (int i = 2; i <= N; i++)
    for (int j = i + 1; j <= N; j++) pq.push({graph[i][j], {i, j}});

  int cnt = 0, sum = 0;
  while (cnt < N - 2) {
    Edge e = pq.top();
    pq.pop();

    int u = e.second.first, v = e.second.second, w = e.first;
    if (find(u) == find(v)) continue;

    cnt++;
    merge(u, v);

    if (w) {
      sum += w;
      ans.push_back({u, v});
    }
  }

  cout << sum << ' ' << ans.size() << endl;
  for (PII p : ans) cout << p.first << ' ' << p.second << endl;
}

void solve() {
  cin >> N >> M;
  graph = vector<vector<int>>(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) p[i] = i;

  vector<PII> tmp;
  int u, v;
  while (M--) {
    cin >> u >> v;
    tmp.push_back({u, v});
  }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> graph[i][j];
  for (PII p : tmp) graph[p.first][p.second] = graph[p.second][p.first] = 0;

  kruskal();
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}