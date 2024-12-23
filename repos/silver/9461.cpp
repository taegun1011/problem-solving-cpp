#define _CRT_SECURE_NO_WARINGS
#include <iostream>
using namespace std;

long long padoban(int n);
long long p[101];

int main() {
	int n,t;
	cin >> t;

	p[1] = p[2] = p[3] = 1;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << padoban(n) << endl;
	}
	
	return 0;
}

long long padoban(int n) {
	if (n <= 3)
		return p[n];
	for (int i = 3; i <= n; i++) {
		p[i] = p[i - 2] + p[i - 3];
	}

	return p[n];
}