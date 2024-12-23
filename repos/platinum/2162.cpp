#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PII pair<int, int>
#define Line pair<PII, PII>

int p[3001];
int sz[3001];

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
	sz[x] += sz[y];

	return sz[x];
}

int ccw(PII a, PII b, PII c) {
	int ax = a.first, ay = a.second, bx = b.first, by = b.second, cx = c.first, cy = c.second;
	long long temp = (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
	return temp > 0 ? 1 : (temp < 0 ? -1 : 0);
}

bool intersect(Line a, Line b) {
	int ab = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
	int cd = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);

	if (ab == 0 && cd == 0) {
		if (a.first > a.second)
			swap(a.first, a.second);
		if (b.first > b.second)
			swap(b.first, b.second);
		return !(a.second < b.first || b.second < a.first);
	}

	return ab <= 0 && cd <= 0;
}

void solve() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		p[i] = i;
		sz[i] = 1;
	}

	vector<Line> Lines(N);
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		Lines[i] = { {x1,y1},{x2,y2} };
	}

	int total = N, mx = 1;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (find(i) == find(j)) continue;

			if (intersect(Lines[i], Lines[j])) {
				mx = max(mx, merge(i, j));
				total--;

				//break하면 나중에 만나는 두 선분을 확인하지 못할 수 있음
			}
		}
	}

	cout << total << '\n' << mx << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}