#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define INF -1e12

int N;
ll dp[1001][1005][3];
vector<int> arr;

ll re_dp(int idx, int cmb, int miss) {
	if (idx == N)
		return 0;
	if (dp[idx][cmb][miss] != INF)
		return dp[idx][cmb][miss];

	ll& ret = dp[idx][cmb][miss];

	ret = re_dp(idx + 1, cmb + 1, 0) + arr[idx] * cmb;
	if(miss + 1 < 3)
		ret = max(ret, re_dp(idx + 1, 1, miss + 1));

	return ret;
}

void solve() {
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j][k] = INF;

	cin >> N;
	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

	ll res = re_dp(0, 1, 0);
	cout << (N < 3 ? res : max(res, 0ll))  << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}