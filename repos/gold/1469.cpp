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

vector<int> ans;

bool check(const vector<int>& arr) {
  int sz = N << 1;
  vector<int> tmp(sz, -1);
  for (int i = 0; i < N; i++) {
    int j;
    for (j = 0; j < sz && tmp[j] >= 0; j++);
    if (j + arr[i] + 1 >= sz || tmp[j] != tmp[j + arr[i] + 1]) return false;
    tmp[j] = tmp[j + arr[i] + 1] = arr[i];
  }

  ans = tmp;
  return true;
}

void solve() {
  cin >> N;
  // 백트래킹 + 브루트포스
  vector<int> arr(N);
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());

  bool found = false;

  do {
    found = check(arr);
  } while (next_permutation(arr.begin(), arr.end()) && !found);

  if (found)
    for (int x : ans) cout << x << ' ';
  else
    cout << -1;
  cout << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}