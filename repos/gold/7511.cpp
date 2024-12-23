#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, K;

vector<int> p;

void init() {
  p = vector<int>(N);
  for (int i = 0; i < N; i++) p[i] = i;
}

int find(int x) {
  if (p[x] == x) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);

  p[y] = x;
}

void solve() {
  cin >> N >> K;
  init();

  int u, v;
  while (K--) {
    cin >> u >> v;
    merge(u, v);
  }
  cin >> M;
  while (M--) {
    cin >> u >> v;
    cout << (find(u) == find(v) ? 1 : 0) << '\n';
  }
}

int main() {
  FASTIO;
  int TC = 1;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    cout << "Scenario " << tc << ":\n";
    solve();
    if (tc < TC) cout << '\n';
  }
}