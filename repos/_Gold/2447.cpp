#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

char symbol[2] = { '*',' ' };

void recursion(vector<vector<char>>& arr, int sr, int sc, int size, int type) {
	if (size == 1)
		arr[sr][sc] = symbol[type];
	else {
		size /= 3;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				recursion(arr, sr + i * size, sc + j * size, size, type || (!type && i == 1 && j == 1));
	}
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<vector<char>> arr(N, vector<char>(N));
	
	recursion(arr, 0, 0, N, 0);
	for (auto str : arr) {
		for (auto c : str)
			cout << c;
		cout << '\n';
	}
}