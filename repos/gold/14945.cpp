#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
int MOD = 10007;

int dp[101][101][101];

int re_dp(int cur, int a, int b) {
  if (cur - 1 && a == b) return 0;
  if (cur == N) return 1;
  if (dp[cur][a][b] != -1) return dp[cur][a][b];
  int& ret = dp[cur][a][b] = 0;
  for (int i = 0; i < 4; i++) {
    ret = ret + re_dp(cur + 1, a + (i >> 1), b + (i & 1));
    ret %= MOD;
  }

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));
  cin >> N;
  cout << re_dp(1, 1, 1);
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}