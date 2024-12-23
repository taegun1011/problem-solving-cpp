#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void LCS(string s1, string s2);
void findPath(int row, int col, string s);

int dp[1001][1001];
int path[1001][1001] = { 0, };
enum { UL = 1, U, L }; //¿ÞÂÊ À§, À§, ¿ÞÂÊ

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	LCS(s1, s2);
}

void LCS(string s1, string s2) {
	int len1 = s1.length(), len2 = s2.length();
	int i, j;

	for (i = 0; i < len1; i++)
		dp[i][0] = 0;
	for (i = 0; i < len2; i++)
		dp[0][i] = 0;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				path[i][j] = UL;
			}
			else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				path[i][j] = U;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				path[i][j] = L;
			}
		}
	}

	cout << dp[len1][len2] << endl;

	findPath(len1, len2, s1);
}

void findPath(int row, int col, string s) {
	string res = "";
	
	int dir;
	while (dir = path[row][col]) {
		switch (dir) {
		case UL:
			res = s[row - 1] + res;
			row--;
			col--;
			break;
		case U:
			row--;
			break;
		case L:
			col--;
		}
	}

	cout << res << endl;
}