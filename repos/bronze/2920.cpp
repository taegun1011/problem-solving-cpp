#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v(8);
	int i;
	for (i = 0; i < 8; i++) {
		cin >> v[i];
	}

	string res = "ascending";

	for (i = 1; i <= 8; i++) {
		if (v[i - 1] != i) {
			break;
		}
	}
	if (i == 9) {
		cout << res << endl;
		return 0;
	}

	res = "descending";
	for (i = 1; i <= 8; i++) {
		if (v[i - 1] != 9-i) {
			break;
		}
	}
	if (i == 9) {
		cout << res << endl;
		return 0;
	}

	res = "mixed";
	cout << res << endl;
}