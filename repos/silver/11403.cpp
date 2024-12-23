#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N;
	cin >> N;

	vector<vector<int>> graph(N, vector<int>(N));
	for (auto& row : graph)
		for (int& x : row)
			cin >> x;

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				graph[i][j] |= graph[i][k] & graph[k][j];

	for (auto row : graph) {
		for (int x : row)
			cout << x << ' ';
		cout << '\n';
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