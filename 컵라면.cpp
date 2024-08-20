#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<PII> arr;

    int d, c;
    for(int i=0;i<N;i++){
        cin >> d >> c;
        arr.push_back({d, c});
    }

    vector<PII> arr_sorted(arr);

    sort(arr_sorted.begin(), arr_sorted.end());
    vector<int> rank(N);
    for(int i=0;i<N;i++){

    }
    
    int ans = 0, cnt = 0;
    for(int i=0;i<N;i++){
        cout << -arr[i].first << ' ' << arr[i].second << endl;
        if(cnt < arr[i].second){
            cnt++;
            ans-=arr[i].first;
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