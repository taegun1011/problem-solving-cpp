#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	map<string, int> M = { {"push",1},{"pop",2},{"size",3},{"empty",4},{"front",5},{"back",6} };
	int N;
	cin >> N;

	queue<int> Q;

	while (N) {
		N--;

		string cmd;
		cin >> cmd;

		switch (M[cmd]) {
		case 1:
			int num;
			cin >> num;
			Q.push(num);
			break;
		case 2:
			if (Q.empty())
				cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
			break;
		case 3:
			cout << Q.size() << '\n';
			break;
		case 4:
			cout << Q.empty() << '\n';
			break;
		case 5:
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.front() << '\n';
			break;
		case 6:
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.back() << '\n';
		}
	}
}