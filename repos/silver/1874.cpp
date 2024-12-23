#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	stack<int> S;
	vector<char> ans;

	int cnt = 1, num, flag = 0;
	while (N) {
		N--;

		cin >> num;

		while (cnt <= num) {
			S.push(cnt++);
			ans.push_back('+');
		}

		while (!S.empty() && num != S.top()) {
			S.pop();
			ans.push_back('-');
		}

		if (S.empty()) {
			flag = 1;
			break;
		}
		S.pop();
		ans.push_back('-');
	}

	if (flag)
		cout << "NO\n";
	else
		for (char c : ans)
			cout << c << '\n';
}