#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;

	int N, Q;
	cin >> N >> Q;

	vector<int> t(N);
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t[i-1];
		if (i != t[i - 1])
			cnt++;
	}
	
	int M, v;
	cin >> M;
	cout << N << ' ' << Q << '\n';

	int left = Q - M - cnt;
	//합치기 전에 출력하면?
	while (M--) {
		cin >> v;
		cout << 2 << " " << v << '\n';
	}

	//필수를 제외한 나머지 쿼리는 미리 대충 처리
	while (left--)
		cout << "1 1 1\n";
	
	//요기가 문젠데
	for (int i = 0; i < N; i++)
		if (i + 1 != t[i])
			cout << 1 << ' ' << i + 1 << ' ' << t[i] << '\n';
}