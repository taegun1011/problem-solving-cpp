#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int cnt[3];

void recursion(vector<vector<short>>& arr, int sr, int sc, int size) {
	short first = arr[sr][sc];

	if (size == 1) {
		cnt[first + 1]++;
		return;
	}
	bool flag = 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[sr + i][sc + j] != first) {
				flag = 0;
				break;
			}
		}
	}

	if (flag)
		cnt[first + 1]++;
	else {
		int subSize = size / 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursion(arr, sr + i * subSize, sc + j * subSize, subSize);
	}
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<vector<short>> arr(N, vector<short>(N));

	for (auto& row : arr)
		for (short& cell : row)
			cin >> cell;

	recursion(arr, 0, 0, N);

	for (int i : cnt)
		cout << i << endl;
}