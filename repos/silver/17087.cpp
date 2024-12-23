#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int findGcd(int a, int b);

void solve() {
	int gcd = v[0];
	for (int i = 1; i < n; i++) {
		gcd = findGcd(gcd, v[i]);
	}

	cout << gcd << '\n';
}

int main() {
	int start;
	cin >> n >> start;

	int pos;
	for (int i = 0; i < n; i++) {
		cin >> pos;
		v.push_back(abs(pos - start));
	}

	solve();
}

int findGcd(int a, int b)
{
	int r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}