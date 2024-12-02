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
  cin >> N >> M;
  vector<bool> visited(N + 1);
  int x, ans = 0;
  while (M--) {
    cin >> x;
    visited[x] = true;
  }
  int prv = 0, tmp = 0;
  for (int i = 1; i <= N; i++) {
    if (visited[i]) continue;

    if (!prv || i > prv + 3) {
      ans += tmp;
      tmp = 7;
    } else {
      tmp += 2 * (i - prv);
    }

    prv = i;
  }
  cout << ans + tmp << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}