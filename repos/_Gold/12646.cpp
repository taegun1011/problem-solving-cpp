#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N, M;

void solve() {
    cin >> N;
    int cnt = 1;
    while(N--){
        string str;
        cin >> str;
        if(!next_permutation(str.begin(), str.end())){
            int first_nonzero = upper_bound(str.begin(), str.end(), '0') - str.begin();
            swap(str[first_nonzero], str[0]);
            str.insert(1, "0");
        }
        
        printf("Case #%d: %s\n", cnt++, str.c_str());
    }
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}