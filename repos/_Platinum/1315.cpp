#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF -1e9

vector<int> S(1001), I(1001), P(1001);

//S, I에서 찍을 수 있는 포인트
int dp[1001][1001];
bool visited[1001][1001];
int N, ans = 0;

int re_dp(int str, int intl) {
	if (str < 0 || intl < 0)
		return INF;

	if (dp[str][intl] != INF)
		return dp[str][intl];

	int& ret = dp[str][intl] = -str - intl;

	//현재 S, I에서 먹을 수 있는 점수는 구해놓되
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (str >= S[i] || intl >= I[i]) {
			ret += P[i];
			cnt++;
		}

	//실제 해당 점수를 먹을 수 있는지 확인 후 값 갱신
	if (visited[str][intl] || (visited[str][intl] =
		(re_dp(str - 1, intl) > 0 && visited[str - 1][intl]) ||
		(re_dp(str, intl - 1) > 0 && visited[str][intl - 1])))
		ans = max(ans, cnt);
	
	return ret;
}

void solve() {
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			dp[i][j] = INF;
	visited[0][0] = 1;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> I[i] >> P[i];
		S[i]--; I[i]--;
	}

	re_dp(999, 999);
	cout << ans << endl;

}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}