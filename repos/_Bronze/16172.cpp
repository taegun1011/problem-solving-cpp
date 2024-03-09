#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	string S, K;
	cin >> S;
	cin >> K;

	string newS;
	for (char ch : S)
		if (isalpha(ch))
			newS += ch;

	cout << (newS.find(K) == -1 ? 0 : 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}