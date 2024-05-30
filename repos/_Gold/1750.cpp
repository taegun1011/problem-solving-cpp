#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define MOD 10000003

int N;
vector<int> arr;

int dp[51][100001];

int gcd(int a, int b) {
	if (!b)
		return a;
	return gcd(b, a % b);
}

int re_dp(int idx, int num) {
	if (idx == N)
		return num == 1;
	if (dp[idx][num] != -1)
		return dp[idx][num];
	
	int& ret = dp[idx][num];
	ret = (re_dp(idx + 1, num) + re_dp(idx + 1, gcd(arr[idx], num))) % MOD;
	
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;
	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

	cout << re_dp(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}