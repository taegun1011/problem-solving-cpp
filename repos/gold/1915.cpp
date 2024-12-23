#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int dp[1001][1001];
vector<string> arr;
int N, M;
int ans;

int re_dp(int cr, int cc) {
	if (cr >= N || cc >= M)
		return 0;
	if (dp[cr][cc] != -1)
		return dp[cr][cc];
	int& ret = dp[cr][cc];
	ret = arr[cr][cc] - '0';
	int r = re_dp(cr, cc + 1);
	int d = re_dp(cr + 1, cc);
	int dr = re_dp(cr + 1, cc + 1);
	if (ret && r && d && dr)
		ret += min({ r, d, dr });
	ans = max(ans, ret);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		arr.push_back(row);
	}
	re_dp(0, 0);
	cout << ans * ans << endl;
	
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}