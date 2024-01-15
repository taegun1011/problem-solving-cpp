#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int dp[1001][1001]; //dp[i][j] = s1[i], s2[j]까지 LCS의 길이
void LCS(string s1, string s2);

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	LCS(s1, s2);
	cout << dp[s1.length()][s2.length()] << endl;

	return 0;
}

void LCS(string s1, string s2) {
	int len1 = s1.length(), len2 = s2.length();

	int i, j;
	for (i = 0; i <= len1; i++)
		dp[i][0] = 0;
	for (j = 0; j <= len2; j++)
		dp[0][j] = 0;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

