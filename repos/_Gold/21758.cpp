#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int N) {
	//구간합 미리 계산
	vector<int> ps(N);
	ps[0] = v[0];
	for (int i = 1; i < N; i++)
		ps[i] = ps[i - 1] + v[i];

	//case 1 : 꿀통이 가운데
	int max = 0, sum = ps[N - 2] - ps[0];
	for (int i = 1; i < N - 1; i++)
		max = std::max(sum + v[i], max);

	//case 2 : 꿀통이 왼쪽 끝
	sum = ps[N - 2];
	for (int i = 1; i < N - 1; i++)
		max = std::max(sum + ps[i - 1] - v[i], max);

	//case 3 : 꿀통이 오른쪽 끝
	sum = ps[N - 1] - ps[0];
	for (int i = 1; i < N - 1; i++)
		max = std::max(sum + ps[N - 1] - ps[i] - v[i], max);

	return max;
}

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	
	for (int&i : v)
		cin >> i;

	cout << solve(v, N) << endl;
}