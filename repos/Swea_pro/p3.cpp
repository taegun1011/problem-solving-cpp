#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 3 [S/W 문제해결 기본] 8일차 - 암호문3
void solve(int tc) {
	list<int> L;

	int N, M;
	cin >> N;

	while (N--) {
		int num;
		cin >> num;
		L.push_back(num);
	}

	cin >> M;

	int x, y, s;
	list<int>::iterator iter;
	while (M--) {
		char cmd;
		cin >> cmd;
		switch (cmd) {
		case 'I':
			cin >> x;
			iter = L.begin();
			while (x--)
				iter++;
			cin >> y;
			while (y--) {
				cin >> s;
				iter = L.insert(iter, s);
				iter++;
			}
			break;
		case 'D':
			cin >> x;
			iter = L.begin();
			while (x--)
				iter++;
			cin >> y;
			while (y--)
				iter = L.erase(iter);
			break;
		case 'A':
			cin >> y;
			while (y--) {
				cin >> s;
				L.push_back(s);
			}
		}
	}

	cout << '#' << tc << ' ';
	iter = L.begin();
	for (int i = 0; i < 10; i++)
		cout << *iter++ << (i == 9 ? '\n' : ' ');
}

int main() {
	FASTIO;
	int TC;
	TC = 10;
	//cin >> TC;
	for (int tc = 1; tc <= TC; tc++)
		solve(tc);
}