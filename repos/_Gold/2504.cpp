#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string str;
	cin >> str;

	int res = 0, tmp;
	stack<char> paren; stack<int> sum;
	map<char, pair<char, int>> M = { {')',{'(', 2}},{']',{'[', 3}} };

	char last = NULL;
	sum.push(0);
	bool flag = 0;

	for (char c : str) {
		if (c == '[' || c == '(') {
			paren.push(c);
			sum.push(0);
		}
		else {

			//), ], (], [)
			if (paren.empty() || paren.top() != M[c].first) {
				flag = 1;
				break;
			}

			//(), []
			if (last == M[c].first) {
				sum.pop();
				sum.top() += M[c].second;
				paren.pop();
			}

			//..)), ..]], ..]), ..)]
			else {
				tmp = sum.top() * M[c].second;
				sum.pop();
				sum.top() += tmp;
				paren.pop();
			}
		}

		last = c;
	}

	if (paren.empty() && !flag)
		cout << sum.top() << endl;
	else
		cout << 0 << endl;
}