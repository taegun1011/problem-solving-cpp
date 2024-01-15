#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//pq 비교자 : class, public bool operator(), 'right'가 조건 만족할 경우 true
class myComp {
public:
	bool operator()(int l, int r) { if (abs(l) == abs(r)) return l > r; return abs(l) > abs(r); }
};

int main() {
	FASTIO
	priority_queue<int, vector<int>, myComp> pq;

	int n; cin >> n;

	int val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val)
			pq.push(val);
		else if (pq.empty())
			cout << 0 << '\n';
		else {
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
}