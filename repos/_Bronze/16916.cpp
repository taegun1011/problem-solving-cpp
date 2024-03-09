#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> failure(string N) {
	int n = N.length();
	vector<int> pi(n);

	int i = 1, j = 0;
	while (i + j <= n) {
		if (j < n && N[i + j] == N[j]) {
			pi[i + j] = j + 1;
			j++;
		}
		else {
			if (j == 0)
				i++;
			else {
				i += j - pi[j - 1];
				j = pi[j - 1];
			}
		}
	}

	return pi;
}

void solve() {
	string H, N;
	cin >> H >> N;

	int h = H.length(), n = N.length();
	vector<int> pi = failure(N);

	int i = 0, j = 0;
	bool flag = 0;
	while (i <= h - n) {
		if (j < n && H[i + j] == N[j]) {
			if (++j == n) {
				flag = 1;
				break;
			}
		}
		else {
			if (j == 0)
				i++;
			else {
				i += j - pi[j - 1];
				j = pi[j - 1];
			}
		}

	}

	cout << (flag ? 1 : 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}