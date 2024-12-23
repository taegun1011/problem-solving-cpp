#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int dp[31][31];
bool arr[31][31];

int re_dp(int r, int c){
    if(r < 0 || c < 0 || arr[r][c])
        return 0;
    if(!r && !c)
        return 1;
    if(dp[r][c] != -1)
        return dp[r][c];
    int &ret = dp[r][c];
    return ret = re_dp(r, c - 1) + re_dp(r - 1, c);
}

void solve() {
    int cnt = 1;
    cin >> N >> M;
    while(N && M){
        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));

        int a, b;
        cin >> a >> b;
        while(a || b){
            arr[a][b] = true;
            cin >> a >> b;
        }
        printf("Map %d: %d\n", cnt++, re_dp(N - 1, M - 1));
        cin >> N >> M;
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}