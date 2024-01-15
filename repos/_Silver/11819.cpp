#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define lll __int128
#define ll long long

ll power(ll A, ll B, ll C) {
	lll a = A, b = B, c = C;
	lll ret = 1;
	while (b) {
		if (b % 2)
			ret = ret * a % c;
		a = a * a % c;
		b /= 2;
	}

	return (ll)ret;
}

int main() {
	ll A, B, C;
	cin >> A >> B >> C;

	cout << power(A, B, C) << endl;
}