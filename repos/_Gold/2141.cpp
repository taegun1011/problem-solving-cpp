#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

// B > |A - C|인 지점
void solve() {
    cin >> N;
    vector<PII> arr(N);
    ll lsum = 0, rsum = 0;
    for(auto& p : arr){
        cin >> p.first >> p.second;
        rsum += p.second;
    }
    sort(arr.begin(), arr.end());

    int ans = 100001;
    ll mx = LLONG_MIN;
    for (int i = 0; i < N; i++) {
        rsum -= arr[i].second;
        if(0ll + arr[i].second - abs(rsum - lsum) > mx){
            ans = i;
            mx = 0ll + arr[i].second - abs(rsum - lsum);
        }

        lsum += arr[i].second;
    }

    cout << arr[ans].first << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}