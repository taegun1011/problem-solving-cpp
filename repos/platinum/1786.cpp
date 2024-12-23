#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> failure(string& P) {
	int p = P.length();
	int i = 1, j = 0;

	vector<int> f(p + 1);
	while (i + j <= p) {
		if (P[j] == P[i + j]) {
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

vector<int> kmp(string& T, string& P, vector<int>& f) {
	int t = T.length(), p = P.length();
	int i = 0, j = 0;

	vector<int> ans;
	while (i <= t - p) {
		if (j < p && P[j] == T[i + j]) {
			if (++j == p)
				ans.push_back(i + 1);
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

	return ans;
}

void solve() {
	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> f = failure(P);

	vector<int> ans = kmp(T, P, f);
	cout << ans.size() << '\n';
	for (int x : ans)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}