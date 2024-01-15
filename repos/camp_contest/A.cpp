#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//N, E, W ,S
int dir[4][4] = { {2,3,0,1},{0,2,1,3},{3,1,2,0},{1,0,3,2} };
char T[4] = { 'O','.', '.', 'P' };
char F[4] = { '.','I', 'P', '.' };
char Lz[4] = { '.','O', 'P', '.' };

int main() {
	FASTIO;

	char d;
	cin >> d;

	char move[4];
	for (int i = 0; i < 4; i++)
		cin >> move[i];

	int K = 0;
	switch (d) {
	case 'N':
		K = 0;
		break;
	case 'E':
		K = 1;
		break;
	case 'W':
		K = 2;
		break;
	case 'S':
		K = 3;
	}

	int i;
	for (i = 0; i < 4; i++) {
		if (move[i] != T[dir[K][i]])
			break;
	}
	if (i == 4) {
		cout << "T\n";
		return 0;
	}

	for (i = 0; i < 4; i++) {
		if (move[i] != F[dir[K][i]])
			break;
	}
	if (i == 4) {
		cout << "F\n";
		return 0;
	}

	for (i = 0; i < 4; i++) {
		if (move[i] != Lz[dir[K][i]])
			break;
	}
	if (i == 4) {
		cout << "Lz\n";
		return 0;
	}

	cout << "?\n";
}