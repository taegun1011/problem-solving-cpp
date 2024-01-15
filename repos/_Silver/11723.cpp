#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void operation(string op);

int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	cin >> M;

	string op;
	while (M > 0) {
		M--;
		cin >> op;
		operation(op);
	}

	return 0;
}

void operation(string op) {
	if (op == "all") { //all
		res = (1 << 20) - 1;
		return;
	}

	int x, temp;
	switch (op[0]) {
	case 'a': //add
		cin >> x;
		temp = 1 << (x - 1);
		res |= temp;
		break;
	case 'r': //remove
		cin >> x;
		temp = ~(1 << (x - 1));
		res &= temp;
		break;
	case 'c': //check
		cin >> x;
		temp = 1 << (x - 1);
		cout << ((res & temp) > 0) << '\n';
		break;
	case 't': //toggle
		cin >> x;
		temp = 1 << (x - 1);
		res ^= temp;
		break;
	case 'e': //empty
		res = 0;
	}
}