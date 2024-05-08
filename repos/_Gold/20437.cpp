#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	string W;
	int K, len;
	cin >> W >> K;
	len = W.length();
	vector<int> ans;
	vector<vector<int>> pos(26, vector<int>(len + 1, -1));

	for (int i = 0; i < 26; i++) {
		int cnt = 0;
		for (int j = 0; j < len; j++)
			if (W[j] == i + 'a')
				pos[i][++cnt] = j;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = K; j <= len; j++) {
			if (pos[i][j] < 0)
				continue;
			ans.push_back(pos[i][j] - pos[i][j - K + 1] + 1);
		}
	}

	if (ans.empty())
		cout << -1 << '\n';
	else {
		auto p = minmax_element(ans.begin(), ans.end());
		cout << *p.first << ' ' << *p.second << '\n';
	}
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}