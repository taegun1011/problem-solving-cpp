#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<int> p;
vector<int> s;

int find(int x) {
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return;
	p[y] = x;
	s[x] += s[y];
}

void solve() {
	N = 1e6;

	p = vector<int>(N + 1);
	s = vector<int>(N + 1, 1);
	for (int i = 1; i <= N; i++)
		p[i] = i;

	cin >> M;

	char cmd;
	int a, b;
	while (M--) {
		cin >> cmd;
		if (cmd == 'I') {
			cin >> a >> b;
			merge(a, b);
		}
		else {
			cin >> a;
			cout << s[find(a)] << '\n';
		}
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