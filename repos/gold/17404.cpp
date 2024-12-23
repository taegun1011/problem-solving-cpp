#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define matrix vector<vector<int>>
#define INF 987654321

int dp[1001][3];

int solve(matrix& cost);

int main() {
	int N;
	cin >> N;

	matrix cost(N, vector<int>(3));
	for (vector<int>& row : cost)
		for (int& i : row)
			cin >> i;

	cout << solve(cost) << endl;
}

int solve(matrix& cost) {
	//0 : red, 1 : green, 2 : blue

	int size = cost.size(), ret = INF;
	
	//첫 집을 start번째 색으로 하는 경우
	for (int start = 0; start < 3; start++) {

		//무조건 start로 칠하도록 초기화
		for (int i = 0; i < 3; i++)
			dp[1][i] = INF;

		dp[1][start] = cost[0][start];

		for (int i = 2; i <= size; i++) {
			for (int j = 0; j < 3; j++) {

				//모듈러 연산을 이용해 다른 두 색깔의 최솟값을 구한다.
				int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;
				int minIdx = dp[i - 1][idx1] < dp[i - 1][idx2] ? idx1 : idx2;

				dp[i][j] = dp[i - 1][minIdx] + cost[i - 1][j];
			}
		}

		//마지막 집의 start색 계산은 무시한다
		dp[size][start] = INF;
		ret = min({ret, dp[size][0], dp[size][1] , dp[size][2] });
	}

	return ret;
}									 


//배운내용 : min({}), 모듈러연산으로 식 편하게 작성, 2차원 배열 &로 입력받기