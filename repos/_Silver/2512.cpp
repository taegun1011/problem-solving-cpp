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

vector<int> arr;

bool check(int mx) {
  int sum = 0;
  for (int x : arr) {
    sum += min(mx, x);
    if (sum > M) return false;
  }
  return true;
}

void solve() {
  cin >> N;
  arr = vector<int>(N);
  int mx = 0;
  for (int& x : arr) {
    cin >> x;
    mx = max(mx, x);
  }
  cin >> M;
  int s = 1, e = mx, m;
  // YYYYNNNN
  while (s < e) {
    m = s + (e - s) / 2 + 1;
    if (check(m))
      s = m;
    else
      e = m - 1;
  }
  cout << s << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}