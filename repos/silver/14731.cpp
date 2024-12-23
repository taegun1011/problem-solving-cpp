#define _CRT_SCURE_NO_WARNINGS
#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector<ll> C;
vector<int> E;
int divisor = 1000000007;
int n;

void solve();

//2^exponÀ» °è»ê
int pow2(int expon);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int i;

	ll coef; int expon;
	for (i = 0; i < n; i++) {
		cin >> coef >> expon;
		C.push_back(coef * expon);
		E.push_back(expon - 1);
	}
	
	solve();
}

void solve() {
	ll result = 0;
	for (int i = 0; i < n; i++)
		result = (result + (C[i] % divisor) * pow2(E[i])) % divisor;

	cout << result << endl;
}

int pow2(int expon) {
	ll res = 1, base = 2;
	while (expon) {
		if (expon % 2) {
			res = res * base % divisor;
		}
		base = base * base % divisor;
		expon /= 2;
	}

	return (int)res;
}