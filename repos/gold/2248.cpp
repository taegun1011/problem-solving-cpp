#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

int N, L;
ll I;

//N자리 중 L자리 비트만 1인 수의 개수
ll dp[32][32];

ll re_dp(int idx, int left) {
	if (left < 0)
		return 0;
	if (idx == N)
		return dp[idx][left] = 1;
	if (dp[idx][left] != -1)
		return dp[idx][left];

	ll& ret = dp[idx][left];
	ret = re_dp(idx + 1, left) + re_dp(idx + 1, left - 1);
	return ret;
}

string re_constr(int idx, int left, string str) {
	if (idx == N)
		return str;
	if (I > dp[idx + 1][left]) {
		str.push_back('1');
		I -= dp[idx + 1][left];
		left--;
	}
	else
		str.push_back('0');

	return re_constr(idx + 1, left, str);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> L >> I;

	re_dp(0, L);
	cout << re_constr(0, L, "") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}