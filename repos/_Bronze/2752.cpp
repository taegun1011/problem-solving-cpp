#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int a, b, c;
	cin >> a >> b >> c;

	if (b < a && b < c)
		swap(a, b);
	else if (c < a && c < b)
		swap(a, c);

	if (b > c)
		swap(b, c);

	cout << a << ' ' << b << ' ' << c << endl;
}