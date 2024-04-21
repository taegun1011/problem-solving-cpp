#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define SIZE 360000

vector<int> fail(vector<char>& S) {
	int s = S.size();
	vector<int> pi(s);

	int i = 1, j = 0;
	while (i + j < s) {
		if (S[j] == S[i + j]) {
			pi[i + j] = j + 1;
			j++;
		}
		else {
			if (!j)
				i++;
			else {
				i += j - pi[j - 1];
				j = pi[j - 1];
			}
		}
	}

	return pi;
}

bool kmp(vector<char>& H, vector<char>& N, vector<int>& pi) {
	int h = H.size(), n = N.size();

	int i = 0, j = 0;
	while (i <= h - n) {
		if (j < n && H[i + j] == N[j]) {
			if (++j == n)
				return true;
		}
		else {
			if (!j)
				i++;
			else {
				i += j - pi[j - 1];
				j = pi[j - 1];
			}
		}
	}

	return false;
}

void solve() {
	vector<char> A(SIZE * 2, 'X'), B(SIZE, 'X');

	int N, x;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		
		A[x] = A[x + SIZE] = 'O';
	}
	for (int i = 0; i < N; i++) {
		cin >> x;
		B[x] = 'O';
	}

	vector<int> pi = fail(B);
	cout << (kmp(A, B, pi) ? "possible" : "impossible") << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}