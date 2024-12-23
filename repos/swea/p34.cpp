#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
enum type {U, Q};

//No. 34 Segment Tree ¿¬½À - 1

vector<int> minseg, maxseg;
vector<int> arr;

void init(int node, int nl, int nr) {
	if (nl == nr) {
		minseg[node] = maxseg[node] = arr[nl];
		return;
	}
	int nm = nl + (nr - nl) / 2;
	init(node * 2, nl, nm);
	init(node * 2 + 1, nm + 1, nr);
	minseg[node] = min(minseg[node * 2], minseg[node * 2 + 1]);
	maxseg[node] = max(maxseg[node * 2], maxseg[node * 2 + 1]);
}

void update(int idx, int val, int node, int nl, int nr) {
	if (nl > idx || nr < idx)
		return;
	if (nl == nr) {
		minseg[node] = maxseg[node] = val;
		return;
	}
	int nm = nl + (nr - nl) / 2;
	update(idx, val, node * 2, nl, nm);
	update(idx, val, node * 2 + 1, nm + 1, nr);
	minseg[node] = min(minseg[node * 2], minseg[node * 2 + 1]);
	maxseg[node] = max(maxseg[node * 2], maxseg[node * 2 + 1]);
}

int query_min(int l, int r, int node, int nl, int nr) {
	if (nl > r || nr < l)
		return INT_MAX;
	if (l <= nl && nr <= r)
		return minseg[node];
	int nm = nl + (nr - nl) / 2;
	return min(query_min(l, r, node * 2, nl, nm), query_min(l, r, node * 2 + 1, nm + 1, nr));
}

int query_max(int l, int r, int node, int nl, int nr) {
	if (nl > r || nr < l)
		return INT_MIN;
	if (l <= nl && nr <= r)
		return maxseg[node];
	int nm = nl + (nr - nl) / 2;
	return max(query_max(l, r, node * 2, nl, nm), query_max(l, r, node * 2 + 1, nm + 1, nr));
}

void solve(int tc) {
	vector<int> ans;
	
	int n, q;
	cin >> n >> q;

	arr = vector<int>(n);
	minseg = vector<int>(n * 4);
	maxseg = vector<int>(n * 4);
	for (int& x : arr)
		cin >> x;

	init(1, 0, n - 1);

	int cmd, a, b;
	while (q--) {
		cin >> cmd >> a >> b;
		switch (cmd) {
		case U:
			update(a, b, 1, 0, n - 1);
			break;
		case Q:
			ans.push_back(query_max(a, b - 1, 1, 0, n - 1) - query_min(a, b - 1, 1, 0, n - 1));
		}	
	}

	cout << "#" << tc << " ";
	int len = ans.size();
	for (int i = 0; i < len; i++)
		cout << ans[i] << (i + 1 == len ? '\n' : ' ');
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
		solve(tc);
}