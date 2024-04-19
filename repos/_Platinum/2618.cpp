#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

vector<PII> pos;
int N, W;
int dp[1005][1005];
int path[1005][1005];

int get_dist(PII a, PII b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int re_dp(int a, int b) {

	if (a == W || b == W)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];

	int cur = max(a, b) + 1;
	PII l_pos = a ? pos[a] : make_pair(1, 1);
	PII r_pos = b ? pos[b] : make_pair(N, N);

	int l_res = re_dp(cur, b) + get_dist(l_pos, pos[cur]);
	int r_res = re_dp(a, cur) + get_dist(r_pos, pos[cur]);

	if (l_res < r_res) {
		path[a][b] = 1;
		return dp[a][b] = l_res;
	}
	path[a][b] = 2;
	return dp[a][b] = r_res;
}

void reconstruct(int a, int b, int idx) {
	if (idx == W)
		return;

	int ans = path[a][b];

	cout << ans << '\n';

	if (ans == 1)
		reconstruct(idx + 1, b, idx + 1);
	else
		reconstruct(a, idx + 1, idx + 1);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> W;

	pos = vector<PII>(W + 1);

	for (int i = 1; i <= W; i++)
		cin >> pos[i].first >> pos[i].second;

	cout << re_dp(0, 0) << endl;

	reconstruct(0, 0, 0);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}