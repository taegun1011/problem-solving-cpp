#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int K;
	cin >> K;

	stack<int> S;

	int num;
	while (K) {
		K--;
		cin >> num;

		if (num)
			S.push(num);
		else
			S.pop();
	}

	long long sum = 0;
	while (!S.empty()) {
		sum += S.top();
		S.pop();
	}

	cout << sum << endl;
}