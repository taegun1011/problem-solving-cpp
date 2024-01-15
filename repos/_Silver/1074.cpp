#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int pos[2][2] = { 0,1,2,3 };

int recursion(int sr, int sc, int size, int r, int c) {
	if (size == 2)
		return pos[r - sr][c - sc];

	int mr = sr + size / 2, mc = sc + size / 2, subArea = size * size / 4;
	if (r >= mr) sr = mr;
	if (c >= mc) sc = mc;

	int area = 0;
	if (sr == mr) area += subArea * 2;
	if (sc == mc) area += subArea;
	return recursion(sr, sc, size / 2, r, c) + area;
}

int main() {
	FASTIO;

	int N, r, c;
	cin >> N >> r >> c;
	int size = pow(2, N);

	cout << recursion(0, 0, size, r, c) << endl;
}