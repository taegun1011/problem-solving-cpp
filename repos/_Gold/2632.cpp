#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int target, m, n;

void solve(vector<int>& A, vector<int>& B) {

	int cnt = 0;
	map<int, int> ps_A, ps_B;
	//A와 B의 모든 구간합 계산
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += A[(i + j) % m];
			ps_A[sum]++;

			//피자 전체 크기의 경우의 수는 1
			if (j == m - 1)
				ps_A[sum] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += B[(i + j) % n];
			ps_B[sum]++;
			if (j == n - 1)
				ps_B[sum] = 1;
		}
	}

	//A만 고르는 경우
	for (auto a : ps_A)
		if (a.first == target)
			cnt += a.second;

	//B만 고르는 경우
	for (auto b : ps_B)
		if (b.first == target)
			cnt += b.second;

	//A와 B에서 골고루 고르는 경우
	for (auto b : ps_B) {
		if (b.first < target)
			cnt += b.second * ps_A[target - b.first];
	}

	cout << cnt << endl;
}

int main() {

	cin >> target >> m >> n;

	//원형 배열, %로 접근
	vector<int> A(m), B(n);
	for (int i = 0; i < m; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	solve(A, B);
}

//맵을 사용하지 않았을 경우 : 배열 크기를 피자 전체 크기로 설정