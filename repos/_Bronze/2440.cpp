#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--)
			cout << '*';
		cout << endl;
	}
}