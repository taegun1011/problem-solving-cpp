#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;
vector<int> arr;
int dp[1005];

int re_dp(int cur) {
	if (dp[cur] != -1)
		return dp[cur];

	int& ret = dp[cur] = 1;
	for (int nxt = cur + 1; nxt <= N; nxt++)
		if (arr[cur] < arr[nxt])
			ret = max(ret, re_dp(nxt) + 1);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	arr.push_back(-1);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cout << re_dp(0) - 1 << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}