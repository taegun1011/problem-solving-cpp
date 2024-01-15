#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

char s[2] = { '*', ' ' };
void recursion(vector<string>& arr, int sr, int sc, int size) {
	if (size == 6) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				if (i == 1 && j == 2) continue;
				if (j >= i && j < 6 - i - 1)
					arr[sr - i][sc + j] = '*';
			}
		}
	}
	else {
		size /= 2;
		recursion(arr, sr, sc, size);
		recursion(arr, sr, sc + size, size);
		recursion(arr, sr - size / 2, sc + size / 2, size);
	}
}

int main() {
	FASTIO;

	int N;
	cin >> N;

	vector<string> arr(N, string(N * 2, ' '));

	recursion(arr, N - 1, 0, N * 2);

	for (auto str : arr)
		cout << str << '\n';
}