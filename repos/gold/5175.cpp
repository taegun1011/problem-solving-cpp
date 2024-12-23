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

void parse(vector<int>& arr, int idx, string str) {
  int field = 0, cur = 0;
  for (char ch : str) {
    if (ch == ' ' && cur) {
      field |= (1 << (cur - 1));
      cur = 0;
    } else {
      cur = cur * 10 + ch - '0';
    }
  }

  if (cur) field |= (1 << (cur - 1));

  arr[idx] = field;
}

int countOf1(int num) {
  int ret = 0;
  while (num) {
    ret += num & 1;
    num >>= 1;
  }
  return ret;
}

void solve(int tc) {
  cin >> N >> M;
  string str;
  getline(cin, str);

  cout << "Data Set " << tc << ": ";
  vector<int> arr(M);
  for (int i = 0; i < M; i++) {
    getline(cin, str);
    parse(arr, i, str);
  }

  int target = (1 << N) - 1, ans = target;

  for (int i = 0; i < (1 << M); i++) {
    int cur = 0;
    for (int j = 0; j < M; j++)
      if (i & (1 << j)) cur |= arr[j];
    if (cur == target)
      if (countOf1(ans) > countOf1(i)) ans = i;
  }

  for (int j = 0; j < M; j++)
    if (ans & (1 << j)) cout << (char)('A' + j) << ' ';
  cout << '\n' << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) solve(tc);
}