#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    vector<int> arr(N);
    for(int& x : arr)
        cin >> x;

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < N; i++){
        if(ans + arr[i] == N - i - 2){
            ans += arr[i];
            break;
        }
        else{
            if(ans + arr[i] >= N - i - 1){
                ans = N - i - 1;
                break;
            }
            ans += arr[i];
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