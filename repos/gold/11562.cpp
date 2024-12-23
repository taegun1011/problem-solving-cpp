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

int N, M, K;

void print(vector<vector<int>>& arr) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) cout << arr[i][j] << ' ';
    cout << '\n';
  }
}

void solve() {
  cin >> N >> M;
  vector<vector<int>> arr(N + 1, vector<int>(N + 1, INF));

  int u, v, b;
  while (M--) {
    cin >> u >> v >> b;
    arr[u][v] = 0;
    arr[v][u] = !b;
  }

  for (int i = 1; i <= N; i++) arr[i][i] = 0;
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

  print(arr);
  cin >> K;
  while (K--) {
    cin >> u >> v;
    cout << arr[u][v] << '\n';
  }
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}