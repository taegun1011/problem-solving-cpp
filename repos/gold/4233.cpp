#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll a, int p);
bool isPrime(int p);

//a^p % p = a지만 p가 소수가 아니다
void solve(int p, int a) {
	if (power(a, p) == a)
		if (!isPrime(p)) {
			cout << "yes\n";
			return;
		}
			
	cout << "no\n";
}

int main() {
	int p, a;
	cin >> p >> a;
	while (p != 0 || a != 0) {
		solve(p, a);
		cin >> p >> a;
	}
}

ll power(ll a, int p) {
	ll res = 1, m = p;
	while (p) {
		if (p % 2)
			res = res * a % m;
		a = a * a % m;
		p /= 2;
	}

	return res;
}
bool isPrime(int p) {
	int i = (int)sqrt(p);
	for (; i >= 2; i--) {
		if (p % i == 0)
			return false;
	}
	return true;
}