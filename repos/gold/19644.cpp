#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M, L, K;

void solve() {
    cin >> N >> L >> K >> M;
    vector<int> arr(N);
    for (int& x : arr)
        cin >> x;

    bool flag = true;
    int sum = 0;
    queue<int> Q;
    for (int i = 0; i < N;i++){
        int cur = 1;

        if(Q.size() == L){
            sum -= Q.front();
            Q.pop();
        }

        if(arr[i] - K * sum > K){
            if(M > 0){
                M--;
                cur = 0;
            }
            else{
                flag = false;
                break;
            }
        }

        sum += cur;

        Q.push(cur);
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