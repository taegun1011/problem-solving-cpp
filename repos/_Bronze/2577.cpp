#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int a, b, c;
	cin >> a >> b >> c;

	int mul = a * b * c;
	vector<int> v(10);

	int m = 10;
	while (mul) {
		v[mul % m]++;
		mul /= 10;
	}

	for (int i : v)
		cout << i << endl;
}