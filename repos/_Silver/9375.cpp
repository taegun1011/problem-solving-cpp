#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int N;

void solve() {
    cin >> N;

    map<string, int> M;
    string str;
    while(N--){
        cin >> str >> str;
        M[str]++;
    }

    int mul = 1;
    for(auto p : M)
        mul *= p.second + 1;
    cout << mul - 1 << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}