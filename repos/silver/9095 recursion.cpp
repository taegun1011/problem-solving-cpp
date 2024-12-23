#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int recursion(int a) {
	if (a == 1)
		return 1;	//1
	if (a == 2)
		return 2;	//1+1, 2
	if (a == 3)
		return 4;	//1+1+1, 1+2, 2+1, 3

	return recursion(a - 1) + recursion(a - 2) + recursion(a - 3);
}

int main() {
	int TC, n;
	cin >> TC;
	while(TC>0){
		TC--;
		cin >> n;
		cout << recursion(n) << endl;
	}
}