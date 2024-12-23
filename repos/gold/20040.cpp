#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;
vector<int> p;

void make_set() {
	p.resize(N);
	for (int i = 0; i < N; i++)
		p[i] = i;
}

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	p[y] = x;
}

int main() {
	FASTIO;

	int M;
	cin >> N >> M;
	make_set();

	int ans = 0, a, b;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		if (find(a) != find(b))
			merge(a, b);
		else if (ans == 0)
			ans = i;
	}

	cout << ans << '\n';
}