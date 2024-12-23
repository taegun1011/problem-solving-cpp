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

// NNNYYYY
int bs(int val) {
  int s = 0, e = N - 1, m;
  while (s < e) {
    m = s + (e - s) / 2;
    if (arr[m] >= val)
      e = m;
    else
      s = m + 1;
  }
  return arr[s] == val ? s : -1;
}

bool chk1(int prv1, int prv2, int left) {
  if (left == 0) return true;
  if (left < 0) return false;

  int idx = bs(left);
  return idx != -1 && idx != prv1 && idx != prv2;
}

bool chk2(int prv, int left) {
  if (left == 0) return true;
  if (left < 0) return false;
  for (int i = 0; i < N; i++) {
    if (i == prv) continue;
    if (chk1(prv, i, left - arr[i])) return true;
  }
  return false;
}

bool chk3() {
  for (int i = 0; i < N; i++)
    if (chk2(i, M - arr[i])) return true;
  return false;
}

void solve() {
  cin >> N >> M;
  arr = vector<int>(N);
  for (int& x : arr) cin >> x;
  sort(arr.begin(), arr.end());

  cout << (chk3() ? 1 : 0) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}