#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<vector<int>> root;
vector<int> graph;

void inorder(int l, int r, int level) {
	if (l > r)
		return;

	int m = l + (r - l) / 2;
	root[level].push_back(graph[m]);
	inorder(l, m - 1, level + 1);
	inorder(m + 1, r, level + 1);
}

void solve() {
	int N;
	cin >> N;

	int size = pow(2, N) - 1;
	graph = vector<int>(size);
	for (int& x : graph)
		cin >> x;

	root = vector<vector<int>>(N);

	inorder(0, size - 1, 0);

	for (int i = 0; i < N; i++) {
		for (int node : root[i])
			cout << node << ' ';
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