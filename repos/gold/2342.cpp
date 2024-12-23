#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int move(int from, int to) {
	if (from == 0)
		return 2;
	if (abs(from - to) == 2)
		return 4;
	return 3;
}

//발이 j,k번에 있을 때 i번 위치부터 누르기 위한 필요한 최소 힘
int dp[100001][5][5];

int re_dp(int idx, vector<int>& arr, int l, int r) {
	if (idx == arr.size())
		return 0;
	if (dp[idx][l][r] != -1)
		return dp[idx][l][r];
	int target = arr[idx];

	int& ret = dp[idx][l][r];
	if (l == target || r == target)
		ret = re_dp(idx + 1, arr, l, r) + 1;
	else
		ret = min(re_dp(idx + 1, arr, target, r) + move(l, target), re_dp(idx + 1, arr, l, target) + move(r, target));
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int pos;
	vector<int> arr;
	do {
		cin >> pos;
		arr.push_back(pos);
	} while (pos);
	arr.pop_back();

	cout << re_dp(0, arr, 0, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}