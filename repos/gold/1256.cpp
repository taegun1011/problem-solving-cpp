#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAX 1000000000

int dp[201][101];

//총 n개 알파벳 중 'a'가 r개인 조합의 수
int re_dp(int n, int r) {
	if (r == 0 || r == n)
		return 1;
	if (dp[n][r] != -1)
		return dp[n][r];
	//10억보다 크면 오버플로우가 나고 애초에 답 계산에 필요가 없으므로 최댓값 제한
	return dp[n][r] = min(re_dp(n - 1, r) + re_dp(n - 1, r - 1), MAX);
}

//
void back(int a, int z, int left) {

	//사전순으로 다음번에 오는 문자열이 정답
	//남은 알파벳을 모두 출력한다
	if (left == 1) {
		while (a--)
			cout << 'a';
		while (z--)
			cout << 'z';
		cout << endl;
		return;
	}

	//현 위치에서 a를 골랐을 경우 계속해서 만들 수 있는 경우의 수는 (a+z-1)C(a-1)개
	//a가 없거나, (a+z-1)C(a-1) < left일 경우 z를 선택해야 한다
	
	//ex) 현재 a가 2개, z가 2개, left = 6 : a를 고르면 3C1 = 3개의 문자열을 만들 수 있다
	//6번째 문자열을 골라야 하는데 a를 고르면 3번째가 최대이다. 따라서 z를 골라야 한다
	if (a == 0 || re_dp(a + z - 1, a - 1) < left) {
		cout << 'z';
		back(a, z - 1, left - re_dp(a + z - 1, a - 1));
	}

	//그게 아니라면 a를 선택한다
	else {
		cout << 'a';
		back(a - 1, z, left);
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N, M, K;
	cin >> N >> M >> K;

	int total = re_dp(N + M, N);

	if (total < K)
		cout << -1 << endl;
	else
		back(N, M, K);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}