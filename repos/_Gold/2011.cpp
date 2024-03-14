#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000

int dp[5001];

string code;
int N;

int re_dp(int cur) {
	if (cur == N)
		return 1;
	if (code[cur] == '0')
		return 0;
	if (dp[cur] != -1)
		return dp[cur];
	int& ret = dp[cur] = 0;

	ret = re_dp(cur + 1);

	if (cur + 2 <= N && code.substr(cur, 2) > "00" && code.substr(cur, 2) <= "26")
		ret = (ret + re_dp(cur + 2)) % MOD;

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> code;
	N = code.length();
	cout << re_dp(0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}