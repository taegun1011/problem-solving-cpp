#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> p;

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

//오른쪽을 왼쪽에 병합
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
}

void solve() {

	int N, M, K;
	cin >> N >> M >> K;

	p.resize(N + 1);

	vector<int> card(M);
	for (int& c : card) {
		cin >> c;
		p[c] = c;
	}

	sort(card.begin(), card.end());

	//카드가 없으면 ub로 연결
	int ub = 0;
	for (int i = 1; i <= N; i++) {
		if (!p[i] && ub < M)
			p[i] = card[ub];
		else
			ub++;
	}

	int num;
	while (K--) {
		cin >> num;
		ub = find(num + 1);
		cout << ub << '\n';
		merge(find(ub + 1), ub);
	}
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}