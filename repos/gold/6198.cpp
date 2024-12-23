#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	vector<int> height(N), parent(N, -1), ans(N); //parent : 확인할 수 있는 빌딩의 수
	for (int& i : height)
		cin >> i;

	stack<int> S;

	for (int i = N - 1; i >= 0; i--) {
		while (!S.empty() && height[i] > height[S.top()]) {
			parent[S.top()] = i;
			ans[i] += ans[S.top()] + 1;
			S.pop();
		}
		S.push(i);
	}

	long long sum = 0;
	for (int i : ans)
		sum += i;
	cout << sum << endl;
}