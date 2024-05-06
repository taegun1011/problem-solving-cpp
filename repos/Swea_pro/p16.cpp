#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//문제이름

#define MOD 20171109

int solve() {
	int ans = 0;

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int N, mid;
	cin >> N >> mid;
	max_heap.push(mid);
	
	while (N--) {
		for (int i = 0; i < 2; i++) {
			int num;
			cin >> num;
			if (num > mid)
				min_heap.push(num);
			else
				max_heap.push(num);
		}

		//최대 -> 최소
		while (!max_heap.empty() && max_heap.size() > min_heap.size() + 1) {
			mid = max_heap.top();
			min_heap.push(mid);
			max_heap.pop();
		}

		//최대 <- 최소
		while (!min_heap.empty() && max_heap.size() < min_heap.size() + 1) {
			mid = min_heap.top();
			max_heap.push(mid);
			min_heap.pop();
		}

		mid = max_heap.top();

		ans = (ans + mid) % MOD;
	}

	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}