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

bool check(string str) {
  char prv = '\0';
  for (char ch : str) {
    if (ch == prv) return false;
    prv = ch;
  }

  return true;
}

void solve() {
  string str;
  cin >> str;

  sort(str.begin(), str.end());
  int ans = 0;
  do {
    ans += check(str);
  } while (next_permutation(str.begin(), str.end()));

  cout << ans << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}