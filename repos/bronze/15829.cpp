#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin >> size;

	string plaintext;
	cin >> plaintext;

	int M = 1234567891, i;
	long long a, r = 1, res = 0;
	for (i = 0; i < size;i++) {
		a = plaintext[i] - 96;
		a *= r; a %= M;
		res += a; res %= M;
		r *= 31; r %= M;
	}

	cout << res << endl;
}