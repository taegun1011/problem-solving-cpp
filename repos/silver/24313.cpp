#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b;
	cin >> c;
	cin >> n;

	int result;
	if (a <= c && (a * n + b) <= (c * n)) result = 1;
	else result = 0;

	cout << result << endl;
}