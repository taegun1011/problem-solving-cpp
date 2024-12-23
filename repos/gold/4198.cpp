#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define max2(a,b) (a>b ? a : b)
#define max3(a,b,c) ((a>b)?(a>c ? a : c) : (b>c ? b : c))

enum {front_weight, back_weight, length};

int N;
vector<int> v;

int dp[2001];

void solve() {
	//자신에서부터 시작하는 LIS, LDS
	vector<int> LIS(N + 1, 1), LDS(N + 1, 1), res(N + 1, 1);
	int i, j;

	for (i = N - 1; i >= 1; i--) {
		for (j = N; j > i; j--) {
			if (v[i] < v[j] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1;
			if (v[i] > v[j] && LDS[i] < LDS[j] + 1)
				LDS[i] = LDS[j] + 1;
		}
	}

	for (i = 1; i <= N; i++)
		res[i] = LIS[i] + LDS[i] - 1;

	cout << *max_element(res.begin() + 1, res.begin() + N + 1) << endl;
}

int main() {
	cin >> N;

	if (!N) {
		cout << 0 << endl;
		return 0;
	}

	v.push_back(-1);

	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}

	solve();
}

//떠올린 접근 방식을 구체화해줄 더 나은 TC를 찾아보자
//lower_bound로 LIS 만드는 방법?