#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define INF -1e9
#define UNUSED -2e9

int N, M;

int arr[1001][1001];
int dp[1001][1001][3];

int re_dp(int r, int c, int d){
    if(r == N && c == M)
        return arr[N][M];
    
    if(dp[r][c][d] != UNUSED)
        return dp[r][c][d];

    int &ret = dp[r][c][d];

    //아래
    if(r < N){
        ret = re_dp(r + 1, c, 0) + arr[r][c];
        //왼쪽
        if(d != 2 && c > 1)
            ret = max(ret, re_dp(r, c - 1, 1) + arr[r][c]);
        //오른쪽
        if(d != 1 && c < M)
            ret = max(ret, re_dp(r, c + 1, 2) + arr[r][c]);
    }
    else
        ret = re_dp(r, c + 1, 2) + arr[r][c];

    return ret;
}

void solve() {
    for (int i = 0; i <= 1000;i++)
        for (int j = 0; j <= 1000;j++)
            for (int k = 0; k < 3;k++)
                dp[i][j][k] = UNUSED;

    cin >> N >> M;
    for (int i = 1; i <= N;i++)
        for (int j = 1; j <= M;j++)
            cin >> arr[i][j];

    cout << re_dp(1, 1, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}