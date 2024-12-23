#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

int dp[1001][1001][2];
vector<int> arr;

int re_dp(int l, int r, int t){
    if(l == r)
        return arr[l];
        
    if(dp[l][r][t] != -1)
        return dp[l][r][t];

    int &ret = dp[l][r][t];
    ret = max(re_dp(l + 1, r, 1 - t) + arr[l] * (1 - t),
            re_dp(l, r - 1, 1 - t) + arr[r] * (1 - t));
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    arr = vector<int>(N);
    for(int& x : arr)
        cin >> x;

    cout << re_dp(0, N - 1, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}