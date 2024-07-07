#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, MOD = 10007;

ll power(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll comb(int n, int r){
    ll mul = 1, div = 1;
    for(int i=n-r+1;i<=n;i++)
        mul = mul * i % MOD;
    for(int i=1;i<=r;i++)
        div = div * i % MOD;
    mul = mul * power(div, MOD - 2) % MOD;

    return mul;
}

void solve() {
    cin >> N;
    cout <<  comb(13, N / 4) * comb(52 - N / 4 * 4, N % 4) * (N >= 4) % 10007 << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}