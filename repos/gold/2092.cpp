#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, S, B;
int MOD = 1e6;
vector<int> arr;

int dp[4001][4001];

int re_dp(int idx, int cnt){
    if(idx == M)
        return cnt >= S && cnt <= B;
    int &ret = dp[idx][cnt];
    if(ret != -1)
        return ret;
    ret = 0;
    int nxt = upper_bound(arr.begin(), arr.end(), arr[idx]) - arr.begin();

    for (int i = 0; i + idx <= nxt; i++)
        ret = (ret + re_dp(nxt, cnt + i)) % MOD;
    
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> S >> B;
    arr.resize(M);
    for(int& x : arr)
        cin >> x;
    sort(arr.begin(), arr.end());
    cout << re_dp(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}