#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;

int sum(vector<int>& v) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
}

int main() {
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int max = sum(v);

	//반복문 종료 시 초기값으로 복귀
	while (next_permutation(v.begin(), v.end())) {
		int temp = sum(v);
		if (temp > max)
			max = temp;
	}

	cout << max << endl;
}