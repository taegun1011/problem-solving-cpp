#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> failure(int length, string& S) {
	vector<int> f(length);
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
	//f(len) >= len/2 : 전체가 이미 중복으로 등장, len = f(len)
	//f(len) < len/2 : 한번만 나왔다, ans = len - f(len)
	int L;
	cin >> L;
	string S;
	cin >> S;

	vector<int> f = failure(L, S);
	int len = L;
	while (len > 1 && f[len - 1] > len / 2)
		len = f[len - 1];
	cout << len - f[len - 1] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}