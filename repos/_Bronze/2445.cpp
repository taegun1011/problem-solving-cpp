#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int n;
	cin >> n;

	for (int i = 1; i < 2 * n; i++) {
		int len = min(i, 2 * n - i);
		for (int j = 1; j <= 2 * n; j++) {
			if (j <= len || j > 2 * n - len)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}