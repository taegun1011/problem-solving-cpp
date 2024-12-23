#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int num;
    cin >> N;
    while(N--){
        cin >> num;
        pq.push(num);
    }

    ll ans = 0;
    while(pq.size() > 1){
        ll sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        ans += sum;
        pq.push(sum);
    }

    cout << ans << '\n';
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}