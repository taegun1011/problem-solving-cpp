#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define SIZE 16

int N;

//방문 상태, 마지막 도시
int dp[1 << SIZE][SIZE];
int cost[SIZE][SIZE];

void solve() {
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		if(cost[0][i])
			dp[1 << i][i] = cost[0][i];
	}

	for (int field = 1; field < (1 << N); field++) {

		for (int u = 0; u < N; u++) {
			if ((field & (1 << u)) == 0) continue;

			for (int v = 0; v < N; v++) {
				if ((field & (1 << v)) == 0) continue;

				int a, b;
				if ((a = dp[field ^ (1 << v)][u]) < 0) continue;
				if ((b = cost[u][v]) == 0) continue;
				int& c = dp[field][v];

				c = (c < 0 ? a + b : min(c, a + b));
			}
		}
	}

	cout << dp[(1 << N) - 1][0] << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];

	solve();
}