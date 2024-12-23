#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> v;

ll compute(ll time) {
	ll sum = 0;
	for (int i : v)
		sum += time / i;

	return sum;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	ll start = 0, end = 1e12, mid;
	while (start < end) {
		mid = (start + end) / 2;
		ll balloon = compute(mid);
		if (balloon >= M)
			end = mid;
		else
			start = mid + 1;
	}

	cout << end << endl;
}

//이분탐색을 왜 활용하는가?
//자기자신을 포함하는 이분탐색 - 종료 조건을 (start '<' end)로
//나올 수 있는 최댓값 (탐색 구간)을 파악하기
//10의 제곱수 표기 : 1ek
//결정은 decision 함수 (bool 반환)