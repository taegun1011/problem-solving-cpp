#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
bool checked[MAX + 1];

void eratosthenes() {
	int i, j;
	for (i = 2; i <= MAX; i++) {
		if (!checked[i])
			for (j = i * i; j <= MAX; j += i)
				checked[j] = 1;
	}
	checked[0] = checked[1] = 0;
}

void solve(int n) {
	for (int left = n / 2; left >= 2; left--) {
		int right = n - left;
		if (!checked[left] && !checked[right]) {
			cout << left << ' ' << right << endl;
			return;
		}
	}
}

int main() {
	eratosthenes();

	int TC, n;
	cin >> TC;
	while (TC) {
		TC--;
		cin >> n;
		solve(n);
	}

}