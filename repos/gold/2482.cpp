#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int MOD = 1000000003;
int N, M;

int dp[1001][1001][2];

int re_dp(int cur, int left, int used, int first){
    if(left < 0)
        return 0;

    if(cur >= N){
        if(left || (used && first))
            return 0;
        return 1;
    }
    int &ret = dp[cur][left][used];
    if(ret != -1){
        return ret;
    }
    
    ret = re_dp(cur + 1, left, 0, first);
    if (!used)
        ret += re_dp(cur + 1, left - 1, 1, first);
    return ret %= MOD;
}

void solve() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    int ans = re_dp(1, M, 0, 0);
    
    memset(dp, -1, sizeof(dp));
    ans += re_dp(1, M - 1, 1, 1);
    cout << ans % MOD << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}