#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> D;
	string cmd;

	int N;
	cin >> N;

	map<string, int> M;
	M["push_front"] = 1;
	M["push_back"] = 2;
	M["pop_front"] = 3;
	M["pop_back"] = 4;
	M["size"] = 5;
	M["empty"] = 6;
	M["front"] = 7;
	M["back"] = 8;

	int num;
	while (N > 0) {
		N--;
		cin >> cmd;

		switch (M[cmd])
		{
		case 1:
			cin >> num;
			D.push_front(num);
			break;
		case 2:
			cin >> num;
			D.push_back(num);
			break;
		case 3:
			if (!D.size())
				cout << -1 << '\n';
			else {
				num = D[0];
				D.pop_front();
				cout << num << '\n';
			}
			break;
		case 4:
			if (!D.size())
				cout << -1 << '\n';
			else {
				num = D[D.size()-1];
				D.pop_back();
				cout << num << '\n';
			}
			break;
		case 5:
			cout << D.size() << '\n';
			break;
		case 6:
			num = (D.empty() ? 1 : 0);
			cout << num << '\n';
			break;
		case 7:
			num = (D.empty() ? -1 : D[0]);
			cout << num << '\n';
			break;
		case 8:
			num = (D.empty() ? -1 : D[D.size() - 1]);
			cout << num << '\n';
		}
	}
}