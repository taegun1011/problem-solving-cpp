#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	string str;
	cin >> str;

	int cnt = 0, stk = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			if (str[i + 1] == ')') {//bound °ÆÁ¤ x
				cnt += stk;
				i++;
			}
			else 
				stk++;
		}
		else {
			cnt++;
			stk--;
		}
	}

	cout << cnt << endl;
}