#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define MAX 100000000
#define ll long long
using namespace std;

bool check[MAX] = { 0, };

int main() {
	//에라토스체네스의 체

	vector<ll> prime;

	for (ll i = 2; i <= MAX; i++) {
		if (!check[i]) {
			prime.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
				check[j] = 1;
		}
	}

	int n;
	cin >> n;
	cout << prime[n - 1] << endl;
}