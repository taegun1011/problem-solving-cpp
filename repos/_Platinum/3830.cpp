#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int p[100001];

//루트 노드와의 차이
int diff[100001];

// path compression과 함께 diff도 갱신

int find(int x) {
	if (x == p[x])
		return x;
	int px = find(p[x]);
	diff[x] += diff[p[x]];
	return p[x] = find(px);
}

void merge(int x, int y, int w) {
	int rx = find(x);
	int ry = find(y);

	if (diff[x] >= w + diff[y]) {
		p[ry] = rx;
		diff[ry] = diff[x] - (w + diff[y]);
	}
	else {
		p[rx] = ry;
		diff[rx] = w + diff[y] - diff[x];
	}
}

void solve() {
	int N, M;
	cin >> N >> M;

	while (N || M) {
		for (int i = 1; i <= N; i++) {
			p[i] = i;
			diff[i] = 0;
		}

		while (M--) {
			char cmd;
			cin >> cmd;
			if (cmd == '!') {
				int a, b, w;
				cin >> a >> b >> w;
				if (find(a) != find(b))
					merge(a, b, w);
			}
			else {
				int a, b;
				cin >> a >> b;
				if (find(a) == find(b))
					cout << diff[a] - diff[b];
				else
					cout << "UNKNOWN";
				cout << '\n';
			}
		}

		cin >> N >> M;
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}