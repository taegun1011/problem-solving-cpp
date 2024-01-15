#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	vector<int> v(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> v[i];

	stack<int> S; //아직 수신탑을 찾지 못한 탑 == 왼쪽보다 큰 탑
	vector<int> ans(N + 1);

	for (int i = N; i >= 1; i--) {

		while (!S.empty() && v[i] > v[S.top()]) {
			ans[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}

	while (!S.empty()) {
		ans[S.top()] = 0;
		S.pop();
	}

	for (int i = 1; i <= N; i++)
		cout << ans[i] << (i == N ? '\n' : ' ');
}