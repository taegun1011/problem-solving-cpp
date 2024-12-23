#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

vector<ll> segtree;
vector<ll> arr;

ll init(int cur, int cl, int cr) {
	if (cl == cr)
		return segtree[cur] = arr[cl];
	int m = (cl + cr) / 2;
	return segtree[cur] = init(cur * 2, cl, m) + init(cur * 2 + 1, m + 1, cr);
}

ll query(int l, int r, int cur, int cl, int cr) {
	if (l > cr || r < cl)
		return 0;
	if (l <= cl && cr <= r)
		return segtree[cur];
	int cm = (cl + cr) / 2;
	return query(l, r, cur * 2, cl, cm) + query(l, r, cur * 2 + 1, cm + 1, cr);
}

ll update(int idx, ll num, int cur, int cl, int cr) {
	if (idx < cl || idx > cr)
		return segtree[cur];
	if (cl == cr)
		return segtree[cur] = arr[idx] = num;
	int cm = (cl + cr) / 2;
	return segtree[cur] = update(idx, num, cur * 2, cl, cm) + update(idx, num, cur * 2 + 1, cm + 1, cr);
}

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	segtree.resize(N * 4);
	arr.resize(N);

	for (ll& x : arr)
		cin >> x;

	init(1, 0, N - 1);

	while (M + K) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			M--;
			update(b - 1, c, 1, 0, N - 1);
		}
		else if (a == 2) {
			K--;
			cout << query(b - 1, c - 1, 1, 0, N - 1) << '\n';
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