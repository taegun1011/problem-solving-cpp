#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> failure(vector<char>& T) {
	int length = T.size();
	vector<int> f(length);

	int i = 1, j = 0;
	while (i + j < length) {
		if (T[i + j] == T[j]) {
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

vector<int> kmp(vector<char>& H, vector<char>& N, vector<int>& f) {
	int h = H.size(), n = N.size();
	int i = 1, j = 0;
	vector<int> ans;

	while (i <= h - n) {
		if (j < n && H[i + j] == N[j]) {
			if (++j == n)
				ans.push_back(i);
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

int GCD(int a, int b) {
	if (!b)
		return a;
	return GCD(b, a%b);
}

void solve() {
	int N;
	cin >> N;
	vector<char> str1(N), str2(N);
	for (char& ch : str1)
		cin >> ch;
	for (char& ch : str2)
		cin >> ch;

	str1.resize(N * 2);
	for (int i = 0; i < N; i++)
		str1[N + i] = str1[i];

	vector<int> f = failure(str2);
	vector<int> ans = kmp(str1, str2, f);
	int a = ans.size(), b = N;
	int gcd = GCD(a, b);

	printf("%d/%d\n", a / gcd, b / gcd);
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}