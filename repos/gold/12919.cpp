#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

string S, T;

//0 : ->, 1 : <-
bool recur(int i, int j, int dir) {
	if (j - i + 1 == S.length()) {
		for (int k = 0; k < S.length(); k++)
			if (S[k] != T[(i + k) * (1 - dir) + (j - k) * dir])
				return false;
		return true;
	}

	char h = T[i], t = T[j];
	if (!dir) {
		if (h == 'A') {
			if (t == 'A')
				return recur(i, j - 1, 0);
			else
				return false;
		}
		else {
			if (t == 'A')
				return recur(i, j - 1, 0) | recur(i + 1, j, 1);
			else
				return recur(i + 1, j, 1);
		}
	}
	else {
		swap(h, t);
		if (h == 'A') {
			if (t == 'A')
				return recur(i + 1, j, 1);
			else
				return false;
		}
		else {
			if (t == 'A')
				return recur(i, j - 1, 0) | recur(i + 1, j, 1);
			else
				return recur(i, j - 1, 0);
		}
	}
}

void solve() {
	cin >> S >> T;

	cout << (recur(0, T.length() - 1, 0) ? 1 : 0) << endl;
}

int main() {
	FASTIO;
	int TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}