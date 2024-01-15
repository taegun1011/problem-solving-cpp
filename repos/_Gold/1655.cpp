#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	//최대힙과 최소힙을 적당히 관리하자
	int N;
	cin >> N;

	priority_queue<int, vector<int>> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;

	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;

		//0, 0 -> 1, 0 -> 1, 1 -> 2, 1 -> 2, 2 -> 3, 2 -> ...
		//순으로 관리하되, 매번 min_pq.top()이 max_pq의 모든 원소보다 크도록 관리

		if (max_pq.size() == min_pq.size())
			max_pq.push(val);
		else
			min_pq.push(val);
		while (!min_pq.empty() && min_pq.top() < max_pq.top()) {
			int a = max_pq.top(); max_pq.pop();
			int b = min_pq.top(); min_pq.pop();
			max_pq.push(b);
			min_pq.push(a);
		}

		cout << max_pq.top() << '\n';
	}
}