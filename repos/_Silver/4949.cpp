#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string str;
	getline(cin, str);

	map<char, char> pair = { {')', '('},{']','['} };

	while (str != ".") {
		stack<char> S;
		bool flag = 0;

		for (char c : str) {
			if (c == '(' || c == '[')
				S.push(c);
			else if (c == ']' || c == ')') {
				if (!S.empty () && S.top() == pair[c])
					S.pop();
				else
					flag = 1;
			}
			
		}

		if (!S.empty() || flag)
			cout << "no\n";
		else
			cout << "yes\n";
		getline(cin, str);
	}
}