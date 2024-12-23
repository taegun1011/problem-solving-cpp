#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

void solve() {
    priority_queue<ll, vector<ll>, greater<ll>> minus;
    priority_queue<ll> plus;
    
    cin >> N;

    int num;
    for (int i = 0; i < N;i++){
        cin >> num;
        if(num < 0)
            minus.push(num);
        else
            plus.push(num);
    }

    ll ans = 0;
    while(plus.size() > 1){
        ll a = plus.top();

        if(a <= 1)
            break;
        plus.pop();
        ll b = plus.top();
        if(b <= 1){
            ans += a;
            break;
        }
        plus.pop();
        ans += a * b;
    }

    while(!plus.empty() && plus.top()){
        ans += plus.top();
        plus.pop();
    }

    while(minus.size() > 1){
        ll a = minus.top();
        minus.pop();
        ll b = minus.top();
        minus.pop();
        ans += a * b;
    }

    if(minus.size())
        ans += plus.empty() ? minus.top() : 0;

    cout << ans << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}