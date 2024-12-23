#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF -1e9
#define UNCACHED -2e9

int dp[3005][3005];
int A, B, C, len1, len2;
string s1, s2;

int comp(int i, int j) {
	char a = i < len1 ? s1[i] : ' ';
	char b = j < len2 ? s2[j] : ' ';

	if (a == ' ' || b == ' ')
		return B;

	return a == b ? A : C;
}

int re_dp(int i, int j) {
	if (i == len1 && j == len2)
		return 0;

	if (dp[i][j] != UNCACHED)
		return dp[i][j];

	int& ret = dp[i][j];
	
	if(i < len1 && j < len2)
		ret = re_dp(i + 1, j + 1) + comp(i, j);

	if(i < len1)
		ret = max(ret, re_dp(i + 1, j) + comp(i, len2));

	if(j < len2)
		ret = max(ret, re_dp(i, j + 1) + comp(len1, j));

	return ret;
}

void solve() {
	for (int i = 0; i < 3005; i++)
		for (int j = 0; j < 3005; j++)
			dp[i][j] = UNCACHED;

	cin >> A >> B >> C >> s1 >> s2;
	len1 = s1.length(), len2 = s2.length();

	cout << re_dp(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}