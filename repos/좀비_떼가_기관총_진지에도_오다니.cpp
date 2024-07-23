#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

//거리, 지뢰, 사거리, 데미지
int N, M, L, K;

void solve() {
    cin >> N >> L >> K >> M;
    vector<int> arr(N), cnt(N);
    for(int& x : arr)
        cin >> x;

    bool flag = true;
    for(int i=0;i<N;i++){
        if(arr[i] - K * (cnt[i]) > 0){
            if(M > 0)
                M--;
            else{
                flag = false;
                break;
            }    
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}