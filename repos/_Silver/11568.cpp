#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int dp[1001];
int arr[1001];

int re_dp(int cur){
    if(dp[cur] != -1)
        return dp[cur];
    int& ret = dp[cur] = 1;
    for(int nxt=cur+1;nxt<N;nxt++)
        if(arr[cur] < arr[nxt])
            ret = max(ret, re_dp(nxt) + 1);

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    
    for(int i = 0; i < N;i++)
        cin >> arr[i];
    
    //이거 아닌데..
    int ans = 1;
    for(int i=0;i<N;i++)
        ans = max(ans, re_dp(i));

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}