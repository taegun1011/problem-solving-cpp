#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define MAX 32

int n, res;
int dp[MAX][6];
map <int, vector<int>> blocks = { {0,{1,3,5}} ,{1,{0,4}}, {2,{3}},{3,{0,2}},{4,{1}},{5,{0}} };
void input() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
}
int rec(int idx, int curBlock) {
	if (idx == n - 1)
		return curBlock % 2;
	if (dp[idx][curBlock] != -1) return dp[idx][curBlock];

	auto keys = blocks[curBlock];
	int ret = 0;
	for (int nxt : keys)
		ret += rec(idx + 1, nxt);
	return dp[idx][curBlock] = ret;
}
int solve() {
	if (n % 2 == 1) return 0;
	return rec(0, 0);

}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	input();
	cout << solve();
}