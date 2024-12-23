#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N >> M;
    vector<int> arr(N);
    for(int& x : arr)
        cin >> x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i + 1 < N; i++)
        pq.push({arr[i] - arr[i + 1]});
    

    int ans = arr[N - 1] - arr[0];
    while(M-- > 1){
        ans += pq.top();
        pq.pop();
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