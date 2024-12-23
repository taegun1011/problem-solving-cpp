#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<int> src(N), dst(N), arr(N);
    for(int& x : src)
        cin >> x;
    for(int& x : dst)
        cin >> x;

    int left = 0;
    for (int i = 0; i < N;i++){
        arr[i] = dst[i] - src[i];
        if(arr[i])
            left++;
    }

    int ans = 0;
    while(left){
        for (int i = 0; i < N;i++){
            if(arr[i]){
                int j, mn = arr[i];
                for (j = i + 1; j < N && arr[j] * arr[j - 1] > 0;j++)
                    mn = mn > 0 ? min(mn, arr[j]) : max(mn, arr[j]);
                ans += abs(mn);
                for (int k = i; k < j;k++)
                    if(!(arr[k] -= mn))
                        left--;
                i = j - 1;
            }
        }
    }

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}