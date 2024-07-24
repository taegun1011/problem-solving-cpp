#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int cnt[7], arr[7];

void solve() {
    for (int i = 1; i <= 6;i++)
        cin >> cnt[i];

    int ans = cnt[6];
    ans += cnt[5];
    cnt[1] = max(0, cnt[1] - cnt[5] * 11);
    ans += cnt[4];
    cnt[1] = max(0, cnt[1] - max(0, (cnt[4] * 5 - cnt[2])) * 4);
    cnt[2] = max(0, cnt[2] - cnt[4] * 5);
    ans += (cnt[3] + 3) / 4;
    if(cnt[3] % 4){
        //1개면 5개, 2개면 3개, 3개면 1개까지 가능
        int mx = 7 - (cnt[3] % 4) * 2;
        cnt[1] = max(0, cnt[1] - (36 - 9 * (cnt[3] % 4) - 4 * min(mx, cnt[2])));
        cnt[2] = max(0, cnt[2] - mx);
    }

    ans += (cnt[2] + 8) / 9;
    if(cnt[2] % 9)
        cnt[1] = max(0, cnt[1] - (36 - (cnt[2] % 9 * 4)));
    ans += (cnt[1] + 35) / 36;

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}