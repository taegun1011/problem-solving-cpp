#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int unused = 2;
int nxt[1000005][26];
int chk[1000005];

string insert(string S) {
	int cur = 1;

	string ret;
	string temp = "";
	for (char ch : S) {
		int type = ch - 'a';
		temp += ch;
		if (nxt[cur][type] == -1) {
			if(ret.empty())
				ret = temp;
			nxt[cur][type] = unused++;
		}
		cur = nxt[cur][type];
	}
	chk[cur]++;

	if (ret.empty()) {
		if(chk[cur] > 1)
			temp += to_string(chk[cur]);
		return temp;
	}
	else
		return ret;
}

void solve() {
	memset(nxt, -1, sizeof(nxt));

	int N;
	cin >> N;
	string str;
	while (N--) {
		cin >> str;
		cout << insert(str) << '\n';
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