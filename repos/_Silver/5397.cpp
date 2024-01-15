#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	
	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		string str;
		cin >> str;

		list<char> L;
		list<char>::iterator iter = L.end();
		for (char c : str) {
			switch (c) {
			case '<':
				if (iter != L.begin())
					iter--;
				break;
			case '>':
				if (iter != L.end())
					iter++;
				break;
			case '-':
				if (iter != L.begin()) {
					iter--;
					iter = L.erase(iter);
				}
				break;
			default:
				L.insert(iter, c);
			}
		}

		for (char c : L)
			cout << c;
		cout << '\n';
	}
}