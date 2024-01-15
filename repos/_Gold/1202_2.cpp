#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>
#define ll long long

int main() {
	FASTIO;

	int N, K;
	cin >> N >> K;

	//가격, 무게
	priority_queue<PII> pq;

	for (int i = 0; i < N; i++) {
		int v, w;
		cin >> w >> v;
		pq.push({ v, w });
	}

	multiset<int> MS;

	for (int i = 0; i < K; i++) {
		int bag;
		cin >> bag;
		MS.insert(bag);
	}

	ll res = 0;
	while (!pq.empty()) {

		//가장 비싼 보석
		PII cur(pq.top());
		int v = cur.first, w = cur.second;
		pq.pop();

		//넣을 수 있는 가방의 위치
		multiset<int>::iterator iter = MS.lower_bound(w);

		if (iter != MS.end()) {
			res += v;
			MS.erase(iter);
		}

		if (MS.empty()) break;
	}

	cout << res << endl;
}

//multiset 사용법
//lower_bound는 내부 메소드로 사용해야 O(log n)
//erase 대상을 값으로 하면 해당 값을 전부 삭제하니 하나만 할 때는 반복자로 해야함