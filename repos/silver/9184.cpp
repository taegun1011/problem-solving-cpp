#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int arr[21][21][21];
int w(int a, int b, int c);
void setup();

int main() {
	setup();

	int a, b, c;
	cin >> a >> b >> c;
	while (!(a == -1 && b == -1 && c == -1)) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
		cin >> a >> b >> c;
	}
	return 0;
}

void setup() {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				if (i == 0 || j == 0 || k == 0)
					arr[i][j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				if (i < j && j < k)
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				else
					arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
			}
		}
	}
}

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return arr[20][20][20];
	return arr[a][b][c];
}