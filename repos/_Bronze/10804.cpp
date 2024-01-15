#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	vector<int> v(21);
	for (int i = 1; i <= 20; i++)
		v[i] = i;

	int a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(v.begin() + a, v.begin() + b + 1);
	}

	for (int i : v) {
		if (i)
			cout << i << ' ';
	}
}