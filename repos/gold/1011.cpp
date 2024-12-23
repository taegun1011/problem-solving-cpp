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

  int d = M - N, mx = sqrt(d), left = d - mx * mx;
  cout << mx * 2 - 1 + (left + mx - 1) / mx << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  cin >> TC;
  while (TC--) solve();
}