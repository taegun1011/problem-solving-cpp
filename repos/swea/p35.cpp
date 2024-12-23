#include <vector>
#include <iostream>

#define ll long long
using namespace std;

ll segtree[400055];
ll init(vector<ll>& arr, int node, int nl, int nr) {
	if (nl == nr)
		return segtree[node] = arr[nl] * ((nl & 1) ? -1 : 1);
	int nm = nl + (nr - nl) / 2;
	return segtree[node] = init(arr, node * 2, nl, nm) + init(arr, node * 2 + 1, nm + 1, nr);
}

ll update(int idx, ll val, int node, int nl, int nr) {
	if (nr < idx || nl > idx)
		return segtree[node];
	if (nl == nr)
		return segtree[node] = val * ((idx & 1) ? -1 : 1);
	int nm = nl + (nr - nl) / 2;
	return segtree[node] = update(idx, val, node * 2, nl, nm) + update(idx, val, node * 2 + 1, nm + 1, nr);
}

ll query(int ql, int qr, int node, int nl, int nr) {
	if (qr < nl || nr < ql)
		return 0;
	if (ql <= nl && nr <= qr)
		return segtree[node];
	int nm = nl + (nr - nl) / 2;
	return query(ql, qr, node * 2, nl, nm) + query(ql, qr, node * 2 + 1, nm + 1, nr);
}

void solve() {
	memset(segtree, 0, sizeof(segtree));

	int N, M;
	cin >> N >> M;
	vector<ll> arr(N);
	for (ll& x : arr)
		cin >> x;

	init(arr, 1, 0, N - 1);

	vector<ll> ans;
	int cmd, a, b;
	while (M--) {
		cin >> cmd >> a >> b;
		if (cmd == 0)
			update(a, b, 1, 0, N - 1);
		else
			ans.push_back(query(a, b - 1, 1, 0, N - 1) * ((a & 1) ? -1 : 1));
	}

	for (ll x : ans)
		cout << x << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		cout << '#' << tc << ' ';
		solve();
		cout << '\n';
	}
}