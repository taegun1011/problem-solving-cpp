#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
	FASTIO
	int a, b;
	cin >> a >> b;

	set<int> S;
	int val;
	for (int i = 0; i < a; i++) {
		cin >> val;
		S.insert(val);
	}

	for (int i = 0; i < b; i++) {
		cin >> val;
		S.erase(val);
	}

	cout << S.size() << '\n';
	if (!S.empty()) {
		for (int i : S)
			cout << i << ' ';
	}
	cout << '\n';
}