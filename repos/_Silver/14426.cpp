#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int unused = 2;
int nxt[5000005][26];

void insert(string S) {
	int cur = 1;
	for (char ch : S) {
		int type = ch - 'a';
		if (nxt[cur][type] == -1)
			nxt[cur][type] = unused++;
		cur = nxt[cur][type];
	}
}

bool find(string S) {
	int cur = 1;
	for (char ch : S) {
		int type = ch - 'a';
		cur = nxt[cur][type];
		if (cur == -1)
			return false;
	}

	return true;
}

void solve() {
	memset(nxt, -1, sizeof(nxt));
	int N, M;
	cin >> N >> M;

	string str;
	while (N--) {
		cin >> str;
		insert(str);
	}

	int ans = 0;
	while (M--) {
		cin >> str;
		ans += find(str);
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}