#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

int dir[4][2] = { 0,1,0,-1,-1,0,1,0 };

vector<vector<int>> tile;

vector<PII> pos;

//방향
vector<vector<vector<PII>>> mal;

//0 -> 1, 1 -> 0, 2 -> 3, 3 -> 2
int reverse(int& x) {
	x = 1 - x;
	if (x < 0)
		x += 4;
	return x;
}

int N, K;

bool check(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N&& tile[r][c] < 2;
}

int calc() {
	int cnt = 0;
	while (++cnt <= 1000) {
		for (int i = 0; i < K; i++) {

			int cr = pos[i].first, cc = pos[i].second;
			auto& m = mal[cr][cc];
			if (m[0].first != i)
				continue;

			int nr = cr + dir[m[0].second][0];
			int nc = cc + dir[m[0].second][1];

			//방향이 바뀌지 않을 경우
			if (check(nr, nc)) {
				if (tile[nr][nc] == 1)
					reverse(m.begin(), m.end());
				for (auto p : m) {
					mal[nr][nc].push_back(p);
					pos[p.first] = { nr, nc };
				}
				m.clear();
			}
			else {
				reverse(m[0].second);
				if (check(cr + dir[m[0].second][0], cc + dir[m[0].second][1]))
					i--;
				continue;
			}

			if (mal[nr][nc].size() >= 4)
				return cnt;
		}
	}


	return cnt <= 1000 ? cnt : -1;
}

void solve() {
	cin >> N >> K;

	tile = vector<vector<int>>(N, vector<int>(N));
	for (auto& row : tile)
		for (int& x : row)
			cin >> x;

	pos = vector<PII>(K);

	mal = vector<vector<vector<PII>>>(N, vector<vector<PII>>(N, vector<PII>()));

	for (int i = 0; i < K; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		mal[r - 1][c - 1].push_back({ i, d - 1 });
		pos[i] = { r - 1, c - 1 };
	}

	cout << calc() << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}