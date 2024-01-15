#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MAX 1000000

int dp[MAX + 1];

//너비 우선 탐색, 동적 계획법 : 0부터 N까지 최단거리를 찾는 용도
// 
//핵심 : K >= dp[N]이면 True
//최소 이동 횟수는 dp를 이용해 구한 dp[N]번이다.
//0번 계단에서 텔포를 쓰면 위치 변화 없이 이동 횟수를 뻥튀기 시킬 수 있다.

void solve(int N, int K) {
	fill(dp, dp + MAX + 1, INF);

	for (int i = 1; i <= 5; i++)
		dp[i] = i;

	for (int i = 4; i < N; i++) {
		dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
		if (i + i / 2 <= N)
			dp[i + i / 2] = min(dp[i] + 1, dp[i + i / 2]);
	}

	if (K >= dp[N])
		cout << "minigimbob\n";
	else
		cout << "water\n";
}

int main() {
	int N, K;
	cin >> N >> K;

	solve(N, K);
}