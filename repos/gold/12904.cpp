#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

void solve() {
    string A, B;
    cin >> A >> B;

    int a = A.length(), b = B.length();
    while(b-- > a){
        if(B[b] == 'A')
            B.pop_back();
        else{
            B.pop_back();
            reverse(B.begin(), B.end());
        }
    }
    cout << (A == B ? 1 : 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}