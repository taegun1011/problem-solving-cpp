#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void findPath(vector<int>& v, int* path, int start) {
	stack<int> S;
	S.push(v[start]);

	int i = start;
	while (path[i] != -1) {
		i = path[i];
		S.push(v[i]);
	}

	cout << S.size() << '\n';
	while (!S.empty()) {
		cout << S.top() << ' ';
		S.pop();
	}
}

void LIS(vector<int>& v) {
	int size = v.size();
	int dp[1001], path[1001];
	int i, j;

	fill(dp, dp + 1001, 1);
	fill(path, path + 1001, -1);

	int maxIdx = 0;

	for (i = 1; i < size; i++) {
		for (j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				path[i] = j;
			}
		}
		if (dp[i] > dp[maxIdx])
			maxIdx = i;
	}

	findPath(v, path, maxIdx);
}

int main() {
	int n;
	cin >> n;

	vector<int> v(n);

	for (int& i : v)
		cin >> i;

	LIS(v);
}