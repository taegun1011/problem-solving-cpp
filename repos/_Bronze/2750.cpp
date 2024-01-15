#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(vector<int>& v, int N) {
	int i, j, min_idx;
	for (i = 0; i < N; i++) {
		min_idx = i;
		for (j = i; j < N; j++) {
			if (v[min_idx] > v[j])
				min_idx = j;
		}
		swap(&v[i], &v[min_idx]);
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> v;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}

	insertion_sort(v, N);

	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
}