#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void cantor(int length, int start, char c); //길이, 시작위치, 출력문자

int main() {
	cout.sync_with_stdio(0);
	cout.tie(0);
	int n, powerOf3;

	while (cin >> n) {
		powerOf3 = 1;
		for (int i = 0; i < n; i++)
			powerOf3 *= 3;
		cantor(powerOf3, 0, '-');
		cout << endl;
	}

	return 0;
}

void cantor(int length, int start, char c) {
	if (length == 1) {
		cout << c;
		return;
	}
	length /= 3;
	cantor(length, start, c);
	int mid = start + length;
	cantor(length, mid, ' ');
	int end = mid + length;
	cantor(length, end, c);
}