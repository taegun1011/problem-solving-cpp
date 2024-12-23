#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int A, B;
	cin >> A >> B;

	cout << A + B << endl << A - B << endl << A * B << endl << A / B << endl << A % B << endl;
}