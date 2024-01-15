#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> v;

void recursion(int start, int end, int val, map<int, int>& M) {
	if (start > end) {
		M[val]++;
		return;
	}

	recursion(start + 1, end, val, M);
	recursion(start + 1, end, val + v[start], M);
}

int main() {
	FASTIO;

	int N, S;
	cin >> N >> S;

	v.resize(N);
	for (int& i : v)
		cin >> i;

	sort(v.begin(), v.end());

	map<int, int> L, R;

	recursion(0, N / 2 - 1, 0, L);
	recursion(N / 2, N - 1, 0, R);

	long long res = 0;
	if (!S) res--;

	for (auto p : L)
		res += 1ll * p.second * R[-p.first + S];

	cout << res << endl;
}

//MITM 알고리즘 : 브루트포스의 일종이지만 시간복잡도를 sqrt로 줄일 수 있다
//왼쪽 절반에서 가능한 모든 경우와 오른쪽 절반에서 가능한 모든 경우를 합치면 됨