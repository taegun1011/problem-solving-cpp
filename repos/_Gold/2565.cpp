#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int calcLIS(int* arr, int n, int pos);
int dp[501];

int main() {
	int n;
	cin >> n;

	int wire[501] = { 0, };

	int i_idx, temp, max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> i_idx;
		cin >> temp;
		if (temp > max)
			max = temp;
		wire[i_idx] = temp;
	}

	int max_cross = calcLIS(wire, max, 0);
	cout << n - max_cross << endl;

	return 0;
}

int calcLIS(int* arr, int n, int pos) {

	//start = 처음으로 0이 아닌 값이 나오는 위치, 즉 dp의 시작 위치
	int start;
	for (start = 1; arr[start] == 0; start++);

	int max_length = dp[start] = 1;
	int temp_max;
	for (int i = start+1; i <= n; i++) {
		if (!arr[i]) {
			dp[i] = 0;
			continue;
		}

		temp_max = 0;
		for (int j = 1; j < i; j++) {
			if ((arr[j] < arr[i]) && (temp_max < dp[j]))
				temp_max = dp[j];
		}
		dp[i] = std::max(temp_max + 1, 1);
		if (max_length < dp[i])
			max_length = dp[i];
	}

	return max_length;
}