#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> in, post;

void recursion(int ps, int pe, int is, int sz) {
	int rt = post[pe];
	cout << rt << ' ';

	if (ps < pe) {
		int m = find(in.begin() + is, in.begin() + is + sz, rt) - in.begin();
		int lsz = m - is;
		int rsz = sz - lsz - 1;
		if(lsz)
			recursion(ps, ps + lsz - 1, is, lsz);
		if(rsz)
			recursion(ps + lsz, pe - 1, m + 1, rsz);
	}
}

void solve() {
	//in : left - root - right
	//post : left - right - root
	//pre : root - left - right

	int N;
	cin >> N;

	in.resize(N);
	post.resize(N);

	for (int& i : in)
		cin >> i;
	for (int& i : post)
		cin >> i;

	recursion(0, N - 1, 0, N);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}