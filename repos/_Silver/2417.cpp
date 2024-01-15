#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll limit = (ll)sqrt(LLONG_MAX);

ll bin_search(ll n) {
	ll start = 0, end = limit, mid;
	while (start < end) {
		mid = (start + end) / 2;

		ll mul = mid * mid;
		if (mul < n)
			start = mid + 1;
		else
			end = mid;
	}

	return start;
}

int main() {
	ll n;
	cin >> n;
	//0 <= n <= 2^63-1

	cout << bin_search(n) << endl;
}