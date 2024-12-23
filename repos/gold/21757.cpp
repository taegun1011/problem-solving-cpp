#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

vector<int> sum;

ll dp[100002][5];
int N;

ll re_dp(int idx, int left) {
	if (left < 0)
		return 0;

	if (idx == N)
		return left == 0;

	if (dp[idx][left] != -1)
		return dp[idx][left];

	ll& ret = dp[idx][left] = 0;

	if (sum[idx] * 4 == sum[N] * (4 - left))
		ret += re_dp(idx + 1, left - 1);

	ret += re_dp(idx + 1, left);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;
	vector<int> arr(N + 1);
	sum = vector<int>(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	cout << re_dp(1, 3) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}