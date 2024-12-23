#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	string str;
	cin >> str;

	sort(str.begin(), str.end());
	
	do {
		cout << str << '\n';
	} while(next_permutation(str.begin(), str.end()));
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}