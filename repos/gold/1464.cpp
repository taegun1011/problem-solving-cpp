#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

string str;

void solve() {
    cin >> str;
    int N = str.length();
    for (int i = 0; i < N - 1;i++){
        if(str[i] < str[i + 1]){
            reverse(str.begin(), str.begin() + i + 1);
            reverse(str.begin(), str.begin() + i + 2);
        }
    }

    reverse(str.begin(), str.end());
    cout << str;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}