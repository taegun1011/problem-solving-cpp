#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int MSS(vector<int>& v);

void solve() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int& i : v)
		cin >> i;

	cout << MSS(v) << endl;
}

int main() {
	int TC;
	cin >> TC;

	while (TC) {
		TC--;
		solve();
	}
}

int MSS(vector<int>& v) {
	int size = v.size();
	int ret = v[0], sum = v[0];

	for (int i = 1; i < size; i++) {
		//이전 결과에서 계속 진행하는 경우, 현재 값에서 새로 시작하는 경우 중 최댓값
		sum = max(sum + v[i], v[i]);

		//매 계산마다 최댓값 저장
		ret = max(ret, sum);
	}

	return ret;
}