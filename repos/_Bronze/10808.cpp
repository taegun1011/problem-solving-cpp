#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string s;
	cin >> s;

	vector<int> v(26);
	for (char c : s)
		v[c - 97]++;

	for (int i : v)
		cout << i << ' ';
}