#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int year;
	cin >> year;

	cout << ((year % 4 == 0) && (year % 100 > 0 || year % 400 == 0)) << endl;
}