#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int dp[21][1 << 20];
vector<vector<int>> arr;

int re_dp(int i, int field){
    if(i == N)
        return 0;
    if(dp[i][field] != -1)
        return dp[i][field];
    int &ret = dp[i][field] = 1e9;
    for (int j = 0; j < N;j++){
        if((1 << j) & field)
            continue;
        ret = min(ret, re_dp(i + 1, field | (1 << j)) + arr[i][j]);
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N));

    for(auto& row : arr)
        for(int& x : row)
            cin >> x;

    cout << re_dp(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}