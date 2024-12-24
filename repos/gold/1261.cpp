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

#define Edge pair<int, PII>
int N, M;

vector<string> graph;
vector<vector<int>> dist;

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int dijkstra(int sr, int sc, int er, int ec) {
  dist = vector<vector<int>>(N, vector<int>(M, INF));
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

  pq.push({dist[sr][sc] = 0, {sr, sc}});
  while (!pq.empty()) {
    auto [w, p] = pq.top();
    auto [cr, cc] = p;
    pq.pop();

    if (dist[cr][cc] < w) continue;

    for (int i = 0; i < 4; i++) {
      int nr = cr + dir[i][0], nc = cc + dir[i][1];

      if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
      int d = graph[nr][nc] - '0';
      if (dist[nr][nc] > w + d) pq.push({dist[nr][nc] = w + d, {nr, nc}});
    }
  }

  return dist[er][ec];
}

void solve() {
  cin >> M >> N;
  graph = vector<string>(N);

  for (string& str : graph) cin >> str;
  cout << dijkstra(0, 0, N - 1, M - 1) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}