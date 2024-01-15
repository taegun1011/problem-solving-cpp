#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int n;
	cin >> n;

	vector<int> v(9);
	
	int m = 10;
	while (n) {
		int r = (n % 10 == 9 ? 6 : n % 10);
		v[r]++;
		n /= 10;
	}

	v[6] = (v[6] % 2) ? v[6] / 2 + 1 : v[6] / 2;

	cout << *max_element(v.begin(), v.end()) << endl;
}