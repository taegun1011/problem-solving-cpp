#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int N, X;
	cin >> N >> X;
	
	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	for (int i : v)
		if (i < X)
			cout << i << ' ';
}