#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int greedy(vector<int> p, int n);

int main() {
	int n;
	cin >> n;

	vector<int> p;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		p.push_back(temp);
	}
	sort(p.begin(), p.end());

	cout << greedy(p, n) << endl;
}

int greedy(vector<int> p, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += p[j];
		}
	}

	return sum;
}