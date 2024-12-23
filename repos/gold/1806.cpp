#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 987654321

int main() {
	FASTIO;
	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	//sum 최댓값 10^9
	int sum = 0, mn = INF, j = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		while (sum >= s) {

			//부분합 계산 과정에서 최솟값 저장
			mn = min(mn, i - j + 1);
			sum -= v[j++];
		}
	}

	cout << (mn == INF ? 0 : mn) << endl;
}