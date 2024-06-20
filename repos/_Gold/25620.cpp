#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

//미리 곱해주고 곱한다...

void solve() {
    cin >> N >> M;
    priority_queue<ll, vector<ll>, greater<ll>> pq, res;
    int num;
    while(N--){
        cin >> num;
        if(num)
            pq.push(num);
        else
            cout << num << ' ';
    }

    int x, y;
    while(M--) {
        cin >> x >> y;
        if(y == 1)
            continue;
        vector<ll> arr;
        while(!pq.empty() && pq.top() <= x){
            ll mul = 1ll * pq.top() * y;
            pq.pop();

            if(mul){
                if(mul <= 1e9)
                    arr.push_back(mul);
                else
                    res.push(mul);
            }
            else
                cout << mul << ' ';
        }
        for(ll mul : arr)
            pq.push(mul);
        
     }

    while (!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }

    while (!res.empty()){
        cout << res.top() << ' ';
        res.pop();
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}