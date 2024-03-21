#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define IMP -1e9
#define UNUSED -2e9

//i개 수, j개 구간, 이전 값이 구간에 포함되는가
int dp[101][51][2];
vector<int> arr;
int N, M;

int re_dp(int idx, int left, int used) {
	if (idx == N) {
		return !!left * IMP;
	}

	if (dp[idx][left][used] != UNUSED)
		return dp[idx][left][used];

	int& ret = dp[idx][left][used];

	//포함 안하기
	ret = re_dp(idx + 1, left, 0);

	//계속 포함하기
	if (used) {
		ret = max(ret, re_dp(idx + 1, left, 1) + arr[idx]);
	}

	//새로 포함하기
	else {
		ret = max(ret, re_dp(idx + 1, left - 1, 1) + arr[idx]);
	}

	return ret;
}

void solve() {
	for (auto& r1 : dp)
		for (auto& r2 : r1)
			for (auto& r3 : r2)
				r3 = UNUSED;

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	cout << re_dp(0, M, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}