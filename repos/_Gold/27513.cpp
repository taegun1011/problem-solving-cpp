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

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

// 상하좌우
void straight(int sr, int sc, int er, int ec, int d) {
  while (sr != er || sc != ec) {
    cout << sr << ' ' << sc << '\n';
    sr += dir[d][0];
    sc += dir[d][1];
  }
  cout << sr << ' ' << sc << '\n';
}

// 대각선
void zigzag(int sx, int sy, int ex, int ey, int d) {
  if (sx == ex && sy == ey) {
    cout << sx << ' ' << sy << '\n';
    return;
  }

  // d : 1 (UN 모양), 2(5 모양)
  int cx = sx, cy = sy;
  if (d == 1) {
    while (cx < ex || cy < ey) {
      if (cy < ey) {
        straight(cx, cy, cx, ey, 1);
        cy = ey;
      } else {
        straight(cx, cy, cx, sy, 3);
        cy = sy;
      }
      cx++;
    }
  } else {
    while (cx < ex || cy > ey) {
      if (cx < ex) {
        straight(cx, cy, ex, cy, 2);
        cx = ex;
      } else {
        straight(cx, cy, sx, cy, 0);
        cx = sx;
      }
      cy--;
    }
  }
}

void solve() {
  cin >> N >> M;

  int cr, cc;
  if (~N & 1) {
    cout << N * M << endl;
    zigzag(1, 2, N - 1, M, 1);
    straight(N, M, N, 2, 3);
    straight(N, 1, 1, 1, 0);
    // zigzag(1, 2, N - 1, M, 1);
    // straight(N, M, N, 2, 3);
    // straight(N, 1, 1, 1, 0);
  } else if (~M & 1) {
    cout << N * M << endl;
    zigzag(2, M, N, 2, 2);
    straight(N, 1, 2, 1, 0);
    straight(1, 1, 1, M, 1);
  } else {
    cout << N * M - 1 << endl;
    zigzag(1, 2, N - 2, M, 1);
    zigzag(N - 1, M, N, 3, 2);
    straight(N, 2, N, 1, 3);
    straight(N - 1, 1, 1, 1, 0);
  }
}

int main() {
  FASTIO;
  int TC = 1;
  // cin >> TC;
  while (TC--) solve();
}