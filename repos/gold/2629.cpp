#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define DEFAULT 15000
int dp[31][55001];


int N, M;
vector<int> arr;

int re_dp(int i, int w) {
    if(i == N)
        return w == DEFAULT;
    if(dp[i][w] != -1)
        return dp[i][w];

    int &ret = dp[i][w];
    ret = re_dp(i + 1, w + arr[i]) | re_dp(i + 1, w) | re_dp(i + 1, w - arr[i]);
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    arr = vector<int>(N);
    for(int& x : arr)
        cin >> x;

    cin >> M;

    int num;
    while(M--){
        cin >> num;
        cout << (re_dp(0, num + 15000) == 1 ? 'Y' : 'N') << ' ';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}