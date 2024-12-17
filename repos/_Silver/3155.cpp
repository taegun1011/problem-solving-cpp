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

void solve() {
  cin >> N;
  vector<vector<int>> arr(2, vector<int>(N));
  for (int i = 0; i < 2; i++)
    for (int& x : arr[i]) cin >> x;

  vector<int> ans(N);
  int prv = 0;
  for (int i = 0; i < N; i++) {
    int cur =
        (prv < arr[0][i] && prv > arr[1][i])
            ? prv
            : (abs(prv - arr[0][i]) < abs(prv - arr[1][i]) ? arr[0][i] - 1
                                                           : arr[1][i] + 1);
    ans[i] = prv = cur;
  }

  for (int x : ans) cout << x << ' ';
  cout << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}