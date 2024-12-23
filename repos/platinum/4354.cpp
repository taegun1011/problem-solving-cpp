#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> failure(string& S) {
	int length = S.length();
	vector<int>f(length);

	int i = 1, j = 0;
	while (i + j <= length) {
		if (j < length && S[j] == S[i + j]) {
			f[i + j] = j + 1;
			j++;
		}
		else {
			if (j == 0)
				i++;
			else {
				i += j - f[j - 1];
				j = f[j - 1];
			}
		}
	}

	return f;
}

void solve() {
	//가장 작은 부분 문자열을 찾아서 나눈다
	string S;
	cin >> S;
	while (S.compare(".")) {
		
		vector<int> f = failure(S);
		int len = S.length();
		int ans = S.length() / len;
		while (len > 1 && f[len - 1] * 2 >= len) {
			if (f[len - 1] * 2 == len)
				ans = S.length() / f[len - 1];
			len = f[len - 1];
		}
		cout << ans << '\n';

		cin >> S;
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}