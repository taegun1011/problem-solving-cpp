#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);
	for (int& x : arr)
		cin >> x;
	sort(arr.begin(), arr.end());

	//차가 큰 K - 1개 구간을 건너뛰자
	vector<int> diff;
	for (int i = 0; i + 1 < N; i++)
		diff.push_back(arr[i + 1] - arr[i]);
	sort(diff.begin(), diff.end());

	int sum = 0;
	for (int i = 0; i < N - K; i++)
		sum += diff[i];
	cout << sum << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}