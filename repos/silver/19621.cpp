#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

int dp[26][26];
vector<pair<PII, int>> arr;

int re_dp(int cur, int last){
    if(cur > N)
        return 0;
    if(dp[cur][last] != -1)
        return dp[cur][last];
    int &ret = dp[cur][last] = re_dp(cur + 1, last);
    if(arr[cur].first.first >= arr[last].first.second)
        ret = max(ret, re_dp(cur + 1, cur) + arr[cur].second);

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    arr = vector<pair<PII, int>>(N + 1);
    for (int i = 1; i <= N;i++)
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;

    sort(arr.begin(), arr.end());

    cout << re_dp(1, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}