#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;
double S;

int dp[6667];
vector<pair<int, PII>> arr;

int re_dp(int cur) {
	if (cur == N)
		return 0;
	if (dp[cur] != -1)
		return dp[cur];
	int& ret = dp[cur] = 0;
	int t1 = arr[cur].first, x1 = arr[cur].second.first, y1 = arr[cur].second.second;

	for (int nxt = N; nxt > cur; nxt--) {
		int t2 = arr[nxt].first, x2 = arr[nxt].second.first, y2 = arr[nxt].second.second;
		double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		int t = ceil(dist / S);
		if (t1 + t <= t2)
			ret = max(ret, re_dp(nxt) + 1);
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> S;
	arr.resize(N + 1);

	int t, x, y;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> t;
		arr[i] = { t, {x, y} };
	}

	//t로 오름차순 정렬 후 dp
	sort(arr.begin(), arr.end());

	cout << re_dp(0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}