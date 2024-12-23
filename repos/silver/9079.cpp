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

int dir[8] = {0b111000000, 0b000111000, 0b000000111, 0b100100100,
              0b010010010, 0b001001001, 0b100010001, 0b001010100};

int bfs(int s) {
  queue<PII> Q;
  Q.push({s, 0});

  vector<bool> visited(512);
  visited[s] = true;

  while (!Q.empty()) {
    auto p = Q.front();
    Q.pop();

    int cur = p.first, cnt = p.second;

    if (cur == 0 || cur == 511) return cnt;

    for (int i = 0; i < 8; i++) {
      int nxt = cur ^ dir[i];
      if (!visited[nxt]) {
        visited[nxt] = true;
        Q.push({nxt, cnt + 1});
      }
    }
  }

  return -1;
}

void solve() {
  int cur = 0;
  char ch;
  for (int i = 0; i < 9; i++) {
    cin >> ch;
    if (ch == 'H') cur = cur | (1 << i);
  }

  cout << bfs(cur) << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  cin >> TC;
  while (TC--) solve();
}