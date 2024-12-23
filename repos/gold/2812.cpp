#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, K, tmp;
	cin >> N >> K;
	tmp = K;

	string str, ans;
	cin >> str;

	stack<char> S;
	for (char ch : str) {
		if (K) {
			while (!S.empty() && K && S.top() < ch) {
				S.pop();
				K--;
			}

			S.push(ch);

			if (!K) {
				while (!S.empty()) {
					ans.push_back(S.top());
					S.pop();
				}
				reverse(ans.begin(), ans.end());
			}
		}
		else
			ans.push_back(ch);
	}
	if (K) {
		while (!S.empty()) {
			ans.push_back(S.top());
			S.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans.substr(0, N - tmp) << endl;
	}
	else
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