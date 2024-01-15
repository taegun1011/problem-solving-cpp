#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int pos[1001];
short dir[3] = { -1,1,0 };

int main() {
	memset(pos, -1, sizeof(pos));

	FASTIO;
	int N, K;
	cin >> N >> K;

	//동생의 1000초 후 위치까지 기록한다
	int t;
	for (t = 0; K <= 500000; t++) {
		K += t;
		pos[t] = K;
	}

	queue<pair<int, int>> Q;
	Q.push({ N, 0 });

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		int cr = cur.first, cc = cur.second;
		if (cr == pos[cc]) {
			cout << cc << endl;
			return 0;
		}

		for (int i = 0; i < 3; i++) {
			int nr = cr + dir[i], nc = cc + 1;
			if (nr == cr) nr *= 2;

			if (nr < 0 || nr > 500000) continue;
			if (nc < t)
				Q.push({ nr, nc });
		}
	}

	cout << -1 << endl;
}