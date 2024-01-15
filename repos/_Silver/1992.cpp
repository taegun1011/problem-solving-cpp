#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void recursion(vector<string>& arr, int sr, int sc, int size) {
	char first = arr[sr][sc];

	if (size == 1) {
		cout << first;
		return;
	}

	bool flag = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i + sr][j + sc] != first) {
				flag = 0;
				break;
			}
		}
	}

	if (flag)
		cout << first;
	else {
		cout << '(';
		int subSize = size / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recursion(arr, sr + i * subSize, sc + j * subSize, subSize);
		cout << ')';
	}
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<string> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	recursion(arr, 0, 0, N);
	cout << endl;
}