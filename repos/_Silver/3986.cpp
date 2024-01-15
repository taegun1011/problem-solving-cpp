#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	string str;
	int cnt = 0;
	while (N) {
		N--;
		cin >> str;

		stack<char> S;

		for (char c : str) {
			if (!S.empty() && c == S.top())
				S.pop();
			else
				S.push(c);
		}
		
		if(S.empty())
			cnt++;
	}

	cout << cnt << endl;
}