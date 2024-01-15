#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int N, L;
	cin >> N >> L;

	vector<int> v(N);
	for (int& i : v)
		cin >> i;

	deque<int> D; //값 대신 인덱스를 저장

	for (int i = 0; i < N; i++) {
		while (!D.empty() && v[D.back()] > v[i])
			D.pop_back();
		D.push_back(i);

		while (!D.empty() && D.front() < max(0, i - L + 1))
			D.pop_front();
		cout << v[D.front()] << ' ';
	}
}