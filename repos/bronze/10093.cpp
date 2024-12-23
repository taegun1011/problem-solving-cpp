#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

int main() {
	FASTIO;
	ll A, B;
	cin >> A >> B;
	if (A > B)
		swap(A, B);
	int n = (B == A ? 0 : B - A - 1);

	cout << n << endl;
	for (int i = 1; i <= n; i++)
		cout << A + i << ' ';
}