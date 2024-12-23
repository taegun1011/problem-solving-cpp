#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int k);

int main() {
	int n, k;

	cin >> n >> k;

	cout << recursion(n, k) << endl;
}

int recursion(int n, int k) {
	if (k == 0 || k == n)
		return 1;
	if (k == 1 || k == n - 1)
		return n;
	return recursion(n - 1, k - 1) + recursion(n - 1, k);
}