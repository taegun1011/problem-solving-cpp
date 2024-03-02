#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int failure(string& T) {
	int i = 1, j = 0;
	int length = T.length();
	vector<int> f(length);
	int ret = 0;

	while (i + j <= length) {
		if (T[j] == T[i + j]) {
			f[i + j] = j + 1;
			ret = max(ret, f[i + j++]);
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

	return ret;
}

void solve() {
	string S;
	cin >> S;
	int N = S.length();

	int ans = 0;
	for (int s = 0; s < N; s++) {
		//failure를 여기 가져와도 될듯
		string T = S.substr(s);
		ans = max(ans, failure(T));
	}
	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}