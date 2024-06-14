#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

#define LOG 17
int N, M;

//up[i][j] : i부터 i + 2^(j - 1) - 1 까지의 최솟값
int up[100001][LOG];

int rmq(int l, int r, int ret){
    int diff = r - l + 1;
    for (int i = LOG - 1; i >= 0;i--){
        if(diff & (1 << i)){
            ret = min(ret, up[l][i]);
            l += 1 << i;
        }
    }

    return ret;
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N;i++)
        cin >> up[i][0];

    for (int j = 1; j < LOG;j++)
        for (int i = 0; i + (1 << j) - 1 < N;i++)
            up[i][j] = min(up[i][j - 1], up[i + (1 << (j - 1))][j - 1]);


    while (M--) {
        int l, r;
        cin >> l >> r;
        int ans = 1e9;
        cout << rmq(l - 1, r - 1, ans) << '\n';
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}