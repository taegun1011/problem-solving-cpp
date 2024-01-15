#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int solve() {
	//시작부터 LIS를 구하고 끝부터 LDS를 구한다.
	int LIS[1001], LDS[1001], LBS[1001];

	int i, j;
	//LIS
	fill(LIS, LIS + 1001, 1);

	for (i = 2; i <= N; i++) {
		int max = 1;
		for (j = 1; j < i; j++) {
			if (v[j] < v[i] && LIS[j] + 1 > LIS[i])
				LIS[i] = LIS[j] + 1;
		}
	}

	//LDS
	fill(LDS, LDS + 1001, 1);

	for (i = N - 1; i >= 1; i--) {
		int max = 1;
		for (j = N; j > i; j--) {
			if (v[j] <v[i] && LDS[j] + 1 > LDS[i])
				LDS[i] = LDS[j] + 1;
		}
	}

	for (i = 1; i <= N; i++)
		LBS[i] = LIS[i] + LDS[i] - 1;

	return *max_element(LBS + 1, LBS + N);
}

int main() {
	cin >> N;
	int val;
	v.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}

	cout << solve() << endl;
}