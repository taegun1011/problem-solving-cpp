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

vector<vector<int>> board(10, vector<int>(10));
int score;

void print() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i >= 4 && j >= 4) continue;
      cout << board[i][j] << ' ';
    }
    cout << endl;
  }
}

vector<PII> get_block(int t, int r, int c) {
  vector<PII> block;
  block.push_back({r, c});
  if (t == 2) block.push_back({r, c + 1});
  if (t == 3) block.push_back({r + 1, c});
  return block;
}

void put_block(vector<PII>& block) {
  for (auto p : block) board[p.first][p.second] = 1;
}

bool block_down(vector<PII>& block) {
  for (auto p : block)
    if (p.first + 1 == 10 || board[p.first + 1][p.second]) return false;

  for (auto& p : block) p.first++;
  return true;
}

bool block_right(vector<PII>& block) {
  for (auto p : block)
    if (p.second + 1 == 10 || board[p.first][p.second + 1]) return false;

  for (auto& p : block) p.second++;
  return true;
}

void put(int t, int sr, int sc) {
  vector<PII> block = get_block(t, sr, sc);
  do {
  } while (block_down(block));
  put_block(block);

  block = get_block(t, sr, sc);
  do {
  } while (block_right(block));
  put_block(block);
}

void line_down(int r, int d, bool isForce) {
  for (int c = 0; c < 4; c++) {
    if (r + d < 10) board[r + d][c] = board[r][c];
    if (r + d < 10 || isForce) board[r][c] = 0;
  }
}

void line_right(int c, int d, bool isForce) {
  for (int r = 0; r < 4; r++) {
    if (c + d < 10) board[r][c + d] = board[r][c];
    if (c + d < 10 || isForce) board[r][c] = 0;
  }
}

void clear() {
  int cnt = 0;
  bool found;

  // down
  for (int i = 9; i >= 6; i--) {
    found = true;
    for (int j = 0; j < 4; j++) {
      if (board[i][j] != 1) {
        found = false;
        break;
      }
    }
    if (found) {
      cnt++;
      for (int j = 0; j < 4; j++) board[i][j] = 0;
    }
  }
  for (int i = 8; i >= 4; i--) {
    for (int j = i; j + 1 < 10; j++) {
      found = true;
      for (int k = 0; k < 4; k++) {
        if (board[j + 1][k]) {
          found = false;
          break;
        }
      }
      if (!found) break;
      line_down(j, 1, 0);
    }
  }
  // right
  for (int i = 9; i >= 6; i--) {
    found = true;
    for (int j = 0; j < 4; j++) {
      if (board[j][i] != 1) {
        found = false;
        break;
      }
    }
    if (found) {
      cnt++;
      for (int j = 0; j < 4; j++) board[j][i] = 0;
    }
  }
  for (int i = 8; i >= 4; i--) {
    for (int j = i; j + 1 < 10; j++) {
      found = true;
      for (int k = 0; k < 4; k++) {
        if (board[k][j + 1]) {
          found = false;
          break;
        }
      }
      if (!found) break;
      line_right(j, 1, 0);
    }
  }

  score += cnt;
}

void move() {
  int cnt = 0;

  // down
  for (int i = 4; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j]) {
        cnt++;
        break;
      }
    }
  }
  if (cnt)
    for (int i = 9; i >= 4; i--) line_down(i, cnt, 1);

  cnt = 0;

  // right
  for (int i = 4; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[j][i]) {
        cnt++;
        break;
      }
    }
  }
  if (cnt)
    for (int i = 9; i >= 4; i--) line_right(i, cnt, 1);
}

int count_block() {
  int ret = 0;
  for (int i = 6; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      ret += board[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 6; j < 10; j++) {
      ret += board[i][j];
    }
  }
  return ret;
}

void solve() {
  cin >> N;
  int t, x, y;
  while (N--) {
    cin >> t >> x >> y;
    put(t, x, y);
    clear();
    move();
  }

  cout << score << '\n' << count_block() << endl;
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}