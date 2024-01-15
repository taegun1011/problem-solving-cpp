#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> graph(501, vector<int>(501)), dp(501, vector<int>(501, -1));
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };

//그냥 DFS를 돌려도 답은 나온다
//메모이제이션을 활용할 수 있을까?
//만약 이미 값이 존재하면 (dp[i][j] != -1) 그 값을 활용한다

bool inRange(int num) {
	return num >= 0 && num < N;
}

int DFS(int row, int col) {
	int res = 1;

	for (int i = 0; i < 4; i++) {
		int nr = row + dir[i][0];
		int nc = col + dir[i][1];
		if (inRange(nr) && inRange(nc) && graph[row][col] < graph[nr][nc]) {
			if (dp[nr][nc] != -1) {
				res = max(res, dp[nr][nc] + 1);
			}
			else
				res = max(res, DFS(nr, nc) + 1);
		}
	}

	return dp[row][col] = res;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];


	int res = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			res = max(res, DFS(i, j));

	cout << res << endl;
}

//메모이제이션 -> 이미 계산해둔 곳은 저장해놓고 활용하면 된다
//탐색 방식이 특정 조건을 만족하면 visited가 필요하지 않을 수도 있다.
//여기서는 계속 자신보다 큰 값으로만 이동하므로, 같은 곳을 여러 번 방문할 수는 있지만, 무한루프를 돌지는 않는다