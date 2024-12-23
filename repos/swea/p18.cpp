#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 18 문자열 교집합

int solve() {
	int n, m;
	cin >> n >> m;
	set<string> S;
	string str;
	while (n--) {
		cin >> str;
		S.insert(str);
	}
	int ans = 0;
	while (m--) {
		cin >> str;
		ans += S.find(str) != S.end();
	}
	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}