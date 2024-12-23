#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[205];
int N;

int re_dp(vector<int>& arr, int i) {
	if (i == N)
		return 1;
	if (dp[i] != -1)
		return dp[i];
	int& ret = dp[i] = 1;
	for (int j = i + 1; j <= N; j++)
		if (arr[i] < arr[j])
			ret = max(ret, re_dp(arr, j) + 1);
	return ret;
}

int lis(vector<int>& arr) {
	memset(dp, -1, sizeof(dp));
	
	return re_dp(arr, 0) - 1;
}

void solve() {
	cin >> N;

	vector<int> arr;
	arr.push_back(0);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	cout << N - lis(arr) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}