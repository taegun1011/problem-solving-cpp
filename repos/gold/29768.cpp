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
  for (int i = 0; i < N - M + 1; i++) cout << 'a';
  for (int i = 1; i < M; i++) cout << (char)('a' + i);
  cout << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}