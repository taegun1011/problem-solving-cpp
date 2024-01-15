#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int getMinimumCoin(int n, int k, int* arr);

int main() {
	int n, k;
	cin >> n >> k;
	int* coin = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout << getMinimumCoin(n, k, coin) << endl;
}

int getMinimumCoin(int n, int k, int* arr) {
	int count = 0, i = n - 1;
	while (k > 0) {
		while (k >= arr[i]) {
			k -= arr[i];
			count++;
		}
		i--;
	}

	return count;
}
