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

set<string> S;

int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
bool check(string a, string b) {
  char r1 = a[0], r2 = b[0], c1 = a[1], c2 = b[1];
  for (int i = 0; i < 8; i++) {
    if (r1 - r2 == dir[i][0] && c1 - c2 == dir[i][1]) return true;
  }
  return false;
}
void solve() {
  N = 36;
  string cur, prev = "", start;

  bool flag = true;
  while (N-- && flag) {
    cin >> cur;
    S.insert(cur);
    if (prev == "")
      start = cur;
    else if (!check(cur, prev))
      flag = false;
    prev = cur;
  }

  cout << (flag && S.size() == 36 && check(start, cur) ? "Valid" : "Invalid")
       << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}