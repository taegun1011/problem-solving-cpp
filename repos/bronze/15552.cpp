#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int T;
	cin >> T;

	int A, B;
	while (T) {
		T--;
		cin >> A >> B;
		cout << A + B << '\n';
	}
}