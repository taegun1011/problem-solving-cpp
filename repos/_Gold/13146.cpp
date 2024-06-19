#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

//우상향으로 만들기

void solve() {
    cin >> N;

    //S의 원소는 우하향
    stack<int> S;

    int num;
    ll ans = 0;
    while(N--){
        cin >> num;
        if(S.empty())
            S.push(num);
        else {
            if(S.top() == num)
                continue;
            
            if(S.top() < num){
                ans += num - S.top();
                while(!S.empty() && S.top() < num)
                    S.pop();
                S.push(num);
            }
            S.push(num);
        }
    }

    while(S.size() > 1) {
        int a = S.top();
        S.pop();
        ans += S.top() - a;
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