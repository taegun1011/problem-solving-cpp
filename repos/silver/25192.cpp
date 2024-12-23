#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main() {
	FASTIO
	int n;
	cin >> n;

	string str;
	map<string, bool> M;
	int cnt = 0;

	//ENTER와 ENTER 사이의 입력은 map의 value를 증가
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "ENTER")
			M.clear();
		else {
			if (!M[str]) {
				cnt++;
				M[str] = 1;
			}
		}
	}
		
	cout << cnt << '\n';
}