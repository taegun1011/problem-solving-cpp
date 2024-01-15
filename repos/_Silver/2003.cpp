#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int m) {
	int sum = 0, cnt = 0;
	int start = 0, end;
	for (end = 0; end < v.size(); end++) {
		sum += v[end];
		while (sum > m)
			sum -= v[start++];
		if (sum == m)
			cnt++;
	}
	return cnt;
}

int main() {
	//투 포인터
	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	cout << solve(v, m) << endl;
}