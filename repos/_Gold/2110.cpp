#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool decision(int dist, int C) {
	int cnt = 1;
	int front = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[front] >= dist) {
			cnt++;
			front = i;
		}

		if (cnt >= C)
			return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, C;
	cin >> N >> C;

	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());
	//정렬 후, 거리를 이분탐색하며 매 거리마다 설치 가능한 공유기 수를 구한다

	int l = 0, r = 1e9, mid;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (decision(mid, C))
			l = mid;
		else
			r = mid - 1;
	}

	cout << l << endl;
}

//왜 답이지?
//꼭 v[0]에서 출발하는 편이 나은가?
//v[1] ~ v[3] >= dist면 v[0] ~ v[3]도 >= dist
//최대 YYYNNN, 최소 NNNYYY로 그림을 그리자