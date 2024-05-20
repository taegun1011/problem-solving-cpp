#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 22 »çÅÁ ºÐ¹è

#define ll long long
int pow2(int num, int expon, ll divisor) {
	ll base = 2, mul = 1;
	while (expon) {
		if (expon & 1)
			mul = (mul * base) % divisor;
		base = base * base % divisor;
		expon >>= 1;
	}

	return (int)(mul * num % divisor);
}

int solve() {
	int A, B, K, total;
	cin >> A >> B >> K;
	total = A + B;

	A = pow2(A, K, total);
	B = total - A;

	return min(A, B);
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}