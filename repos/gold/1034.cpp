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

bool check(string str) {
  int cnt = count(str.begin(), str.end(), '0');
  return (K >= cnt) && (~(K - count(str.begin(), str.end(), '0')) & 1);
}

void solve() {
  cin >> N >> M;
  vector<string> board(N);
  for (auto& str : board) cin >> str;
  cin >> K;
  map<string, int> cnt;
  for (auto str : board) cnt[str]++;
  int mx = 0;
  for (auto p : cnt)
    if (check(p.first)) mx = max(mx, p.second);
  cout << mx << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}