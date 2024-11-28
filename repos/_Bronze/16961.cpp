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

int T[366], S[366];

void solve() {
  cin >> N;

  char c;
  int s, e;

  int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0;
  while (N--) {
    cin >> c >> s >> e;
    if (c == 'T')
      for (int i = s; i <= e; i++) T[i]++;
    else
      for (int i = s; i <= e; i++) S[i]++;
    ans5 = max(ans5, e - s + 1);
  }

  for (int i = 1; i <= 366; i++) {
    ans1 += (T[i] + S[i] > 0);
    ans2 = max(ans2, T[i] + S[i]);
    if (T[i] && T[i] == S[i]) {
      ans3++;
      ans4 = max(ans4, T[i] + S[i]);
    }
  }
  cout << ans1 << '\n'
       << ans2 << '\n'
       << ans3 << '\n'
       << ans4 << '\n'
       << ans5 << '\n';
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}