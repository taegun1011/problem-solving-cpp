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

vector<int> W, V;
int dp[1001][10001];

int re_dp(int idx, int left) {
  if (left <= 0 || idx == M) return 0;
  if (dp[idx][left] != -1) return dp[idx][left];

  int& ret = dp[idx][left] = re_dp(idx + 1, left);
  if (left >= W[idx]) ret = max(ret, re_dp(idx + 1, left - W[idx]) + V[idx]);

  return ret;
}

int iter_dp() {
  memset(dp, 0, sizeof(dp));
  for (int i = W[0]; i <= N; i++) dp[0][i] = V[0];
  for (int i = 1; i < M; i++)
    for (int j = 0; j <= N; j++)
      dp[i][j] = (j >= W[i] ? max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i])
                            : dp[i - 1][j]);

  return dp[M - 1][N];
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cin >> N >> M;
  W = vector<int>(M);
  V = vector<int>(M);

  for (int i = 0; i < M; i++) cin >> V[i] >> W[i];

  //   cout << re_dp(0, N) << endl;
  cout << iter_dp() << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}