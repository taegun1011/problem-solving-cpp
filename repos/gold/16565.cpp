#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, MOD = 10007;

int dp[14][53];
int comb[53][53];

int re_comb(int n, int r){
    int &ret = comb[n][r];
    if(r == 0 || r == n)
        return ret = 1;
    if(comb[n][r])
        return comb[n][r];
    return ret = (re_comb(n - 1, r) + re_comb(n - 1, r - 1)) % MOD;
}

//a개 쌍 중 b개를 선택했을 때 최소 하나 이상 겹치는 경우의 수
int re_dp(int a, int b){
    //4개 이하로 선택하면 겹칠 수 없다
    if(b < 4)
        return 0;
    if(dp[a][b] != -1)
        return dp[a][b];
    int &ret = dp[a][b] = 0;
    for (int i = 4; i <= b; i += 4){
        //a개 쌍 중 i개 포카드를 만들 i/4개를 선택하는 경우의 수
        int x = re_comb(a, i / 4);
        //i개 포카드를 제외한 나머지 카드들을 선택하는 경우의 수
        int y = re_comb(a * 4 - i, b - i);
        //나머지 카드를 선택할 때 한 쌍이라도 겹치는 경우의 수
        int z = re_dp(a - i / 4, b - i);

        //포카드를 고르고, 나머지 카드는 겹치지 않게 고른다
        ret += x * (y - z);
        ret %= MOD;
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    cin >> N;
    cout << re_dp(13, N) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}