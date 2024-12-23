#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int a, b, c;
	cin >> a >> b >> c;

	int prize;
	if (a == b && b == c)
		prize = 10000 + a * 1000;
	else if (a == b)
		prize = 1000 + a * 100;
	else if (b == c)
		prize = 1000 + b * 100;
	else if (c == a)
		prize = 1000 + c * 100;
	else
		prize = max({ a,b,c }) * 100;

	cout << prize << endl;
}