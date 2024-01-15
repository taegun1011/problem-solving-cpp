#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int src, int dest);
void move(int src, int dest);

int main() {
	cout.sync_with_stdio(0);
	cout.tie(0);

	int n;
	cin >> n;

	int count = (int)pow(2, n);
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 3);
}

void hanoi(int n, int src, int dest) {
	if (n == 1) {
		move(src, dest);
	}
	else {
		int middle = 6 / (dest * src); //1,2,3 중 나머지
		hanoi(n - 1, src, middle);
		move(src, dest);
		hanoi(n - 1, middle, dest);
	}

}

void move(int src, int dest) {
	cout << src << ' ' << dest << '\n';
}