#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string str;
	cin >> str;

	list<char> L;
	for (char c : str)
		L.push_back(c);
	list<char>::iterator iter = L.end();

	int N;
	cin >> N;
	while (N) {
		N--;
		char cmd;
		cin >> cmd;

		switch (cmd) {
		case 'L':
			if(iter != L.begin())
				iter--;
			break;
		case 'D':
			if (iter != L.end())
				iter++;
			break;
		case 'B':
			if (iter != L.begin()) {
				iter--;
				iter = L.erase(iter);
			}
			break;
		case 'P':
			char c;
			cin >> c;

			L.insert(iter, c);
		}
	}

	for (char c : L)
		cout << c;
	cout << '\n';
}