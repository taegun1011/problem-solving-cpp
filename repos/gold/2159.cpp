#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long
#define lim = 100000;
#define INF 1e15

int dir[5][2] = { 0,0,-1,0,0,1,1,0,0,-1 };
int N;

vector<PII> arr;
ll dp[100005][6];

inline int get_dist(PII a, PII b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll re_dp(int idx, int d) {
	if (idx == N)
		return 0;
	if (dp[idx][d] != -1)
		return dp[idx][d];

	ll& ret = dp[idx][d] = INF;

	PII cur = arr[idx];
	cur.first += dir[d][0];
	cur.second += dir[d][1];


	for (int d = 0; d < 5; d++) {
		PII nxt = arr[idx + 1];
		nxt.first += dir[d][0];
		nxt.second += dir[d][1];

		if (nxt.first < 0 || nxt.first > 100000 || nxt.second < 0 || nxt.second > 100000)
			continue;

		ret = min(ret, re_dp(idx + 1, d) + get_dist(cur, nxt));
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;
	arr = vector<PII>(N + 1);
	cin >> arr[0].first >> arr[0].second;

	for (int i = 1; i <= N; i++)
		cin >> arr[i].first >> arr[i].second;

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