#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;
vector<int> arr;
vector<PII> segtree;

PII init(int node, int nl, int nr) {
	if (nl == nr)
		return segtree[node] = { arr[nl], nl };
	int nm = (nl + nr) / 2;
	return segtree[node] = min(init(node * 2, nl, nm), init(node * 2 + 1, nm + 1, nr));
}

PII update(int idx, int val, int node, int nl, int nr) {
	if (nr < idx || nl > idx)
		return segtree[node];
	if (nl == nr)
		return segtree[node] = { val, nl };
	int nm = (nl + nr) / 2;
	return segtree[node] = min(update(idx, val, node * 2, nl, nm), update(idx, val, node * 2 + 1, nm + 1, nr));
}

PII query(int l, int r, int node, int nl, int nr) {
	if (nl > r || nr < l)
		return { INT_MAX, 0 };
	if (l <= nl && nr <= r)
		return segtree[node];
	int nm = (nl + nr) / 2;
	return min(query(l, r, node * 2, nl, nm), query(l, r, node * 2 + 1, nm + 1, nr));
}

void solve() {
	cin >> N;
	arr = vector<int>(N);
	segtree = vector<PII>(N * 4);

	for (int& x : arr)
		cin >> x;
	init(1, 0, N - 1);
	cin >> M;

	int cmd, i, j;
	while (M--) {
		cin >> cmd >> i >> j;
		if (cmd == 1)
			update(i - 1, j, 1, 0, N - 1);
		else
			cout << query(i - 1, j - 1, 1, 0, N - 1).second + 1 << '\n';
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