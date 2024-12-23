#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	set<string> v[51];

	string temp;
	while (N) {
		N--;
		cin >> temp;
		v[temp.length()].insert(temp);
	}

	for (auto arr : v)
		for (string s : arr)
			cout << s << '\n';
}