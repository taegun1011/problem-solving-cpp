#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

ll recursive(ll ret, ll base, ll expon, ll div) {
	if (!expon)
		return ret;
	if (expon % 2)
		ret = ret * base % div;

	base = base * base % div;
	return recursive(ret, base, expon / 2, div);
}

int main() {
	FASTIO;
	ll A, B, C;
	cin >> A >> B >> C;

	ll mul = recursive(1, A, B, C);

	cout << mul << endl;
}