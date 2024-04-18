#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

string s;
int dp[501][501];

int re_dp(int l, int r) {
	if (l >= r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];

	int& ret = dp[l][r];
	ret = re_dp(l + 1, r - 1);
	if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c'))
		ret += 2;
	for (int k = l + 1; k < r; k++)
		ret = max(ret, re_dp(l, k) + re_dp(k, r));

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> s;

	cout << re_dp(0, s.length() - 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}