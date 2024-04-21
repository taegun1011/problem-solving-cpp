#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//No. 4 수열 편집
void solve(int tc) {
	list<int> L;

	int N, M, K;
	cin >> N >> M >> K;
	while (N--) {
		int num;
		cin >> num;
		L.push_back(num);
	}

	list<int>::iterator iter;
	int x, y;
	char cmd;
	while (M--) {
		iter = L.begin();
		cin >> cmd;
		switch (cmd) {
		case 'I':
			cin >> x >> y;
			
			while (x--)
				iter++;

			L.insert(iter, y);
			break;
		case 'D':
			cin >> x;
			while (x--)
				iter++;
			L.erase(iter);
			break;
		case 'C':
			cin >> x >> y;
			while (x--)
				iter++;
			*iter = y;
		}
	}

	cout << '#' << tc << ' ';
	if (L.size() - 1 < K)
		cout << -1 << '\n';
	else {
		iter = L.begin();
		while (K--)
			iter++;
		cout << *iter << '\n';
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
		solve(tc);
}