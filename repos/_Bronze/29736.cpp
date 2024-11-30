#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
    int A,B,K,X;
    cin>>A>>B>>K>>X;
    int C=max(0,K-X),D=K+X;

    int ans=0;
    if(C<A){
        if(D>=A)
            ans=min(B,D)-A+1;
    } else if(C<=B){
        ans=min(B,D)-C+1;
    }

    if(ans)
        cout << ans << endl;
    else    
        cout << "IMPOSSIBLE" << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}