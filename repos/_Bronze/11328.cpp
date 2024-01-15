#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	while (N) {
		N--;
		vector<int> alpha(26);

		string str1, str2;
		cin >> str1;
		for (char c : str1)
			alpha[c - 97]++;

		cin >> str2;
		for (char c : str2)
			alpha[c - 97]--;

		bool flag = 0;
		for (int i : alpha)
			if (i) {
				cout << "Impossible\n";
				flag = 1;
				break;
			}
		if(!flag)
			cout << "Possible\n";
	}
}