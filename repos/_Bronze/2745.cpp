#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	string str;
	int b;
	cin >> str >> b;

	int sum = 0, base = 1;
	for (int i = str.length() - 1; i >= 0; i--) {
		char ch = str[i];
		if (isalpha(ch))
			sum += base * (ch - 'A' + 10);
		else
			sum += base * (ch - '0');
		base *= b;
	}

	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}