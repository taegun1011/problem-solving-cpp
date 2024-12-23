#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int N;
	cin >> N;
	stack<int> S;
	map<string, int> M = { {"push",1},{"pop",2} ,{"size",3} ,{"empty",4} ,{"top",5} };

	int num;
	while (N) {
		N--;

		string cmd;
		cin >> cmd;

		switch (M[cmd]) {
		case 1:
			cin >> num;
			S.push(num);
			break;
		case 2:
			if (S.empty())
				cout << -1 << '\n';
			else {
				cout << S.top() << '\n';
				S.pop();
			}
			break;
		case 3:
			cout << S.size() << '\n';
			break;
		case 4:
			cout << S.empty() << '\n';
			break;
		case 5:
			if (S.empty())
				cout << -1 << '\n';
			else
				cout << S.top() << '\n';
		}
	}
}