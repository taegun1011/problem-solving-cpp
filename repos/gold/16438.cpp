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

// 99가 어떻게 가능??
// 2^7 = 128
//
vector<string> result;
void recursion(int s, int e, int lv) {
  if (s == e) return;
  int m = (s + e) / 2;
  cout << s << ' ' << m << ' ' << e << ' ' << lv << endl;
  for (int i = s; i <= m; i++) result[lv][i] = 'A';
  for (int i = m + 1; i <= e; i++) result[lv][i] = 'B';
  recursion(s, m, lv + 1);
  recursion(m + 1, e, lv + 1);
}

void solve() {
  cin >> N;

  string dummy = "A";
  for (int i = 0; i < N - 1; i++) dummy.push_back('B');
  result = vector<string>(7, dummy);
  recursion(0, N - 1, 0);
  for (int i = 0; i < 7; i++) cout << result[i] << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}