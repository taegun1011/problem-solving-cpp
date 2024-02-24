#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int p[200000];
int sz[200000];

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if (px != py) {
		p[py] = px;
		int sx = sz[px], sy = sz[py];
		sz[px] += sy;
	}
	cout << sz[px] << '\n';
}

void solve() {
	for (int i = 0; i < 200000; i++) {
		p[i] = i;
		sz[i] = 1;
	}

	int F;
	cin >> F;

	map<string, int> M;
	int cnt = 1;
	while (F-- > 0) {
		string a, b;
		cin >> a >> b;
		if (!M[a])
			M[a] = cnt++;
		if (!M[b])
			M[b] = cnt++;

		merge(M[a], M[b]);
	}
}

int main() {
	FASTIO;	
	
	int TC;
	cin >> TC;
	while (TC--)
		solve();
}