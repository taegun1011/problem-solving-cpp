#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007

int N;
string str;

int dp[10001][17];
int re_dp(int idx, int cur) {
	if (idx == N)
		return 1;
	if (dp[idx][cur] != -1)
		return dp[idx][cur];

	int& ret = dp[idx][cur] = 0;
	int a = str[idx] - 'A';
	for (int nxt = 1; nxt <= (1 << 4); nxt++)
		if ((nxt & (1 << a)) && (nxt & cur))
			ret = (ret + re_dp(idx + 1, nxt)) % MOD;

	return ret;
}

//No. 6 동아리실 관리하기
void solve(int tc) {
	memset(dp, -1, sizeof(dp));

	cin >> str;
	N = str.length();

	cout << '#' << tc << ' ' << re_dp(0, 0b0001) << '\n';
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		solve(tc);
	}
}