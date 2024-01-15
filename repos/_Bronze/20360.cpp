#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; (1 << i) <= n; i++) {
		if ((1 << i) & n)
			cout << i << ' ';
	}
}