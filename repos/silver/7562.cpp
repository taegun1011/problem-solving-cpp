#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

short dir[8][2] = { -2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,-2,-2,-1 };

void solve() {
	queue<pair<int, int>> Q;

	int l;
	cin >> l;

	vector<vector<int>> dist(l, vector<int>(l));
	int sr, sc, er, ec;
	cin >> sr >> sc >> er >> ec;

	Q.push({ sr,sc });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;

		if (cr == er && cc == ec) break;

		for (int i = 0; i < 8; i++) {
			int nr = cr + dir[i][0], nc = cc + dir[i][1];

			if (nr < 0 || nr >= l || nc < 0 || nc >= l) continue;

			if (!dist[nr][nc]) {
				dist[nr][nc] = dist[cr][cc] + 1;
				Q.push({ nr, nc });
			}
		}
	}

	cout << dist[er][ec] << endl;
}

int main() {
	FASTIO;

	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}