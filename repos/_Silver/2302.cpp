#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//type : 현재 칸과 왼쪽 칸이 비었는가
//0 : 둘다 빔, 1 : 왼쪽 빔, 2 : 현재 빔
int dp[41][3];
int N;
vector<bool> vip;

//현재만 비어있을 경우 -> 현재, 오른쪽에 넣을 수 있다 -> 다음 칸 기준 2, 1
//둘다 비어있을 경우 -> 왼쪽, 현재, 오른쪽에 넣을 수 있다 -> 다음 칸 기준 0, 2, 1
//왼쪽만 비어있을 경우 -> 왼쪽에 넣을 수 있다 -> 다음 칸 기준 2
int re_dp(int cur, int type) {
	if (cur > N)
		return type == 2;

	if (dp[cur][type] != -1)
		return dp[cur][type];
	int& ret = dp[cur][type];

	if (vip[cur]) {
		if (type == 1)
			ret = 0;
		else
			ret = re_dp(cur + 1, 2);
	}
	else {
		if (type == 0)
			ret = re_dp(cur + 1, 0) + re_dp(cur + 1, 1) + re_dp(cur + 1, 2);
		else if (type == 1)
			ret = re_dp(cur + 1, 2);
		else
			ret = re_dp(cur + 1, 2) + re_dp(cur + 1, 1);
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int M;
	cin >> N >> M;
	vip.resize(N + 1);

	while (M--) {
		int v;
		cin >> v;
		vip[v] = 1;
	}

	cout << re_dp(1, 2) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}