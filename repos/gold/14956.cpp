#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int nxtQuad[4][4] = { {3,2,1,4},{3,4,1,2},{1,4,3,2},{1,2,3,4} };
int nxtDeg[4][4] = { {1,0,0,3},{0,1,1,2},{3,2,2,1},{2,3,3,0} };

void recursion(int sr, int sc, int size, int dist, int deg) {
	if (size == 2) {
		switch (nxtQuad[deg][dist]) {
		case 1:
			cout << sc + 1 << ' ' << sr + 1;
			break;
		case 2:
			cout << sc << ' ' << sr + 1;
			break;
		case 3:
			cout << sc << ' ' << sr;
			break;
		case 4:
			cout << sc + 1 << ' ' << sr;
			break;
		}
		cout << endl;
		return;
	}

	size /= 2;
	int sqr = size * size;
	int seq = dist / sqr;
	dist -= seq * sqr;

	switch (nxtQuad[deg][seq]) {
	case 1:
		recursion(sr + size, sc + size, size, dist, nxtDeg[deg][seq]);
		break;
	case 2:
		recursion(sr + size, sc, size, dist, nxtDeg[deg][seq]);
		break;
	case 3:
		recursion(sr, sc, size, dist, nxtDeg[deg][seq]);
		break;
	case 4:
		recursion(sr, sc + size, size, dist, nxtDeg[deg][seq]);
	}
}

int main() {
	FASTIO;
	int n, m;
	cin >> n >> m;

	recursion(1, 1, n, m - 1, 0);
}