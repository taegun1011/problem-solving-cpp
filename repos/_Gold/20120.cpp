#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF -987654321

//dp[i][j] : i번째 노트를 콤보 j로 처리했을 때의 최댓값
ll dp[1001][1001];

//visited[i][j] : dp[i][j]이 최댓값일 때 연속해서 틀린 횟수
int visited[1001][1001];
int N;
vector<int> v;

ll solve(vector<int>& v);

int main() {
	cin >> N;
	v.push_back(0);

	int val;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		v.push_back(val);
	}

	cout << solve(v) << endl;
}

ll solve(vector<int>& v) {

	//setup : 모든 노트를 치는 경우
	for (int i = 1; i <= N; i++)
		dp[i][i] = dp[i - 1][i - 1] + (ll)v[i] * i;
	
	//fill
	for (int i = 1; i <= N; i++) {

		//dp[i-1][0 ~ i-1] 중 최댓값과 그 인덱스를 탐색
		int maxCombo = 0;
		ll maxScore = INF;
		for (int j = 0; j < i; j++)
			if (dp[i - 1][j] > maxScore && visited[i][j] < 3) {
				maxCombo = j;
				maxScore = dp[i - 1][j];
			}

		//dp[i][0] = 현재 점수를 포기했을 때, 이전 점수 중 최댓값
		dp[i][0] = maxScore;

		//추가로 1회 연속 놓침
		visited[i][0] = visited[i - 1][maxCombo] + 1;

		//3회 이상 놓치면 0
		if (visited[i][0] >= 3)
			dp[i][0] = INF;

		//dp[i][1~i] = 현재 점수를 쳤을 때
		//노트 1 증가, 콤보 1 증가 -> 대각선 아래로 이동
		for (int j = 1; j <= i; j++) {

			//이전 위치에서 게임 오버됐을 경우 계산 X
			if (visited[i - 1][j - 1] >= 3) {
				dp[i][j] = INF;
				visited[i][j] = visited[i - 1][j - 1];
			}
				

			//아닐 경우 콤보만큼 합산
			else {
				dp[i][j] = dp[i - 1][j - 1] + (ll)v[i] * j;
				visited[i][j] = 0;
			}
		}
	}
	
	return max((ll)0, *max_element(dp[N], dp[N] + N + 1));
}