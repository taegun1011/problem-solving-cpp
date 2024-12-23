#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int mul = a * b;
	int count1, count2, i;
	int small = (a > b ? b : a);

	int GCD = 1;
	for (i = 2; i <= small; i++) {
		count1 = 0;
		count2 = 0;
		while (a % i == 0) {
			count1++;
			a /= i;
		}
		while (b % i == 0) {
			count2++;
			b /= i;
		}
		while (count1 > 0 && count2 > 0) {
			count1--;
			count2--;
			GCD *= i;
		}
	}

	int LCM = mul / GCD;

	cout << GCD << '\n' << LCM << '\n';
}