#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

bool found = false;
int N;

bool check(string str) {
	int len = str.length();
	for (int i = 1; i <= len / 2; i++) {
		bool flag = true;
		for (int j = 0; j < i; j++) {
			char l = str[len - 1 - j - i], r = str[len - 1 - j];
			if (l != r) {
				flag = false;
				break;
			}
		}
		if (flag)
			return false;
	}
	return true;
}

void recursion(string str) {
	if (found)
		return;

	if (str.length() == N) {
		found = true;
		cout << str << endl;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		str.push_back('0' + i);
		if(check(str))
			recursion(str);
		str.pop_back();
	}
}

void solve() {
	cin >> N;

	recursion("");
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}