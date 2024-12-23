#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//1 : 전체 최대 길이, 0 : 현재 최대 길이
int dp[4001][4001][2];
string A, B;

#define TOTAL 1
#define NOW 0

int re_dp(int i, int j, int type) {
	if (i < 0 || j < 0)
		return 0;
	if (dp[i][j][type] != -1)
		return dp[i][j][type];
	int& ret = dp[i][j][type];
	if (type == TOTAL) {
		ret = max(re_dp(i, j - 1, TOTAL), re_dp(i - 1, j, TOTAL));
		if (A[i] == B[j])
			ret = max(ret, re_dp(i - 1, j - 1, NOW) + 1);
	}
	else {
		if (A[i] == B[j])
			ret = re_dp(i - 1, j - 1, NOW) + 1;
		else
			ret = 0;
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> A >> B;
	cout << re_dp(A.length() - 1, B.length() - 1, 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}