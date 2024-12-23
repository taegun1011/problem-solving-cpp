#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 4000005

int root = 1, unused_c = 2, unused_n = 2;

bool chk_c[MAX];
int nxt_c[MAX][26];

bool chk_n[MAX];
int nxt_n[MAX][26];

void insert(const string& S, int type) {
	auto& nxt = type ? nxt_n : nxt_c;
	auto& chk = type ? chk_n : chk_c;
	auto& unused = type ? unused_n : unused_c;

	int cur = root;
	for (char ch : S) {
		if (nxt[cur][ch - 'a'] == -1)
			nxt[cur][ch - 'a'] = unused++;
		cur = nxt[cur][ch - 'a'];
	}
	chk[cur] = true;
}

bool find(const string& S, int idx, int type) {
	const auto& nxt = type ? nxt_n : nxt_c;
	const auto& chk = type ? chk_n : chk_c;

	int len = S.length(), cur = root;
	bool ret = false;

	for (; idx < len; idx++) {
		if (cur == -1) {
			if (type)
				return false;
			break;
		}
		char ch = S[idx];
		if (chk[cur] && !type)
			if (len - idx <= 1000)
				if (ret |= find(S, idx, 1))
					return true;

		cur = nxt[cur][ch - 'a'];
	}
	if (type && cur > 0 && chk[cur])
		return true;
	return ret;
}

void solve() {
	memset(nxt_c, -1, sizeof(nxt_c));
	memset(nxt_n, -1, sizeof(nxt_n));

	int C, N;
	cin >> C >> N;
	string str;
	while (C--) {
		cin >> str;
		insert(str, 0);
	}
	while (N--) {
		cin >> str;
		insert(str, 1);
	}

	int Q;
	cin >> Q;
	while (Q--) {
		cin >> str;
		cout << (find(str, 0, 0) ? "Yes" : "No") << '\n';
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