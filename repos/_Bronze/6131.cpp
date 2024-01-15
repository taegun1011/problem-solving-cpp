#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, n, cnt = 0;
	cin >> n;
	for (b = 1; b <= 500; b++) {
		for (a = b; a <= 500; a++) {
			if (a * a - b * b == n)
				cnt++;
		}
	}

	cout << cnt << endl;
}