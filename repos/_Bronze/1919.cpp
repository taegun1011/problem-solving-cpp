#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string str1, str2;
	cin >> str1 >> str2;

	vector<int> alpha(26);
	for (char c : str1)
		alpha[c - 97]++;
	for (char c : str2)
		alpha[c - 97]--;

	int ans = 0;
	for (int i : alpha)
		if (i >= 0) ans += i;
		else ans -= i;

	cout << ans << endl;
}