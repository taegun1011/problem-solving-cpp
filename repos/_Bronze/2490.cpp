#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int cnt;
	char res;
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		int tmp;
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			if (!tmp) cnt++;
		}
		switch (cnt) {
		case 4:
			res = 'D';
			break;
		case 3:
			res = 'C';
			break;
		case 2:
			res = 'B';
			break;
		case 1:
			res = 'A';
			break;
		default:
			res = 'E';
		}
		cout << res << endl;
	}

}