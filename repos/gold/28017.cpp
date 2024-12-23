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

vector<vector<int>> arr;
int dp[501][501];

int re_dp(int idx, int cur) {
  if (idx == N) return 0;
  if (dp[idx][cur] != INF) return dp[idx][cur];

  int& ret = dp[idx][cur];
  for (int i = 0; i < M; i++) {
    if (i == cur) continue;
    ret = min(ret, re_dp(idx + 1, i) + arr[idx][cur]);
  }

  return ret;
}

void solve() {
  //   memset(dp, -1, sizeof(dp));

  for (int i = 0; i < 501; i++)
    for (int j = 0; j < 501; j++) dp[i][j] = INF;

  cin >> N >> M;
  arr = vector<vector<int>>(N, vector<int>(M));
  for (auto& row : arr)
    for (int& x : row) cin >> x;
  for (int i = 0; i < M; i++) re_dp(0, i);
  cout << *min_element(dp[0], dp[0] + M) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}