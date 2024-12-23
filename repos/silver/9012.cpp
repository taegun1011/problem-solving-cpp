#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		string str, ans = "YES";
		cin >> str;

		stack<char> S;
		for (char c : str) {
			if (c == ')') {
				if (S.empty())
					ans = "NO";
				else
					S.pop();
			}
			else
				S.push(c);
		}

		if (!S.empty())
			ans = "NO";

		cout << ans << endl;
	}
}