#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long greedy(long long*& D, long long*& P, long long n);

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	long long* distance = new long long[n - 1];
	for (long long i = 0; i < n-1; i++)
		cin >> distance[i];

	long long* price = new long long[n];
	for (long long i = 0; i < n; i++)
		cin >> price[i];

	cout << greedy(distance, price, n) << endl;
}

long long greedy(long long*& D, long long*& P, long long n) {
	long long sum = 0, min_price = P[0], i = 0;
	while (i < n - 1) {
		sum += min_price * D[i];
		if (P[i + 1] <= min_price)
			min_price = P[i + 1];
		i++;
	}

	return sum;
}