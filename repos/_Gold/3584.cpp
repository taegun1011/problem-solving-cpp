#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;

	vector<int> p(N + 1);
	vector<bool> visited(N + 1);

	int a, b;
	cin >> a >> b;
	while (N-- > 1) {
		p[b] = a;
		cin >> a >> b;
	}

	while (a) {
		visited[a] = 1;
		a = p[a];
	}

	while (b && !visited[b])
		b = p[b];

	cout << b << endl;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}