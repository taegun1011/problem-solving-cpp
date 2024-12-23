#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N;
	cin >> N;

	char score;

	switch (N/10) {
	case 10:
	case 9:
		score = 'A';
		break;
	case 8:
		score = 'B';
		break;
	case 7:
		score = 'C';
		break;
	case 6:
		score = 'D';
		break;
	default:
		score = 'F';
	}

	cout << score << endl;
}