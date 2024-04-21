#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PII pair<int, int>

//rec1 : 알고리즘 분류(0~100)에 대한 PQ, <난이도, 번호>
vector<priority_queue<PII, vector<PII>, less<PII>>> rec1_pos(101), rec1_neg(101);

//rec2 : 난이도에 대한 PQ
priority_queue<PII, vector<PII>, less<PII>> rec2_pos, rec2_neg;

//rec3 : 문제 난이도에 대한 set, <난이도, 번호>
set<PII> rec3_pos, rec3_neg;

//문제의 현재 난이도
vector<int> level(100001);
//문제의 현재 분류
vector<int> group(100001);

bool is_valid(const PII& p, int x, int g) {
	return p.first * x == level[p.second * x] && (!g || g == group[p.second * x]);
}

void rec1(int g, int x) {
	auto& pq = x > 0 ? rec1_pos[g] : rec1_neg[g];
	while (!pq.empty()) {
		auto cur = pq.top();
		if (is_valid(cur, x, g)) {
			cout << cur.second * x << '\n';
			return;
		}
		pq.pop();
	}
}

void rec2(int x) {
	auto& pq = x > 0 ? rec2_pos : rec2_neg;
	while (!pq.empty()) {
		auto cur = pq.top();
		if (is_valid(cur, x, 0)) {
			cout << cur.second * x << '\n';
			return;
		}
		pq.pop();
	}
}

void rec3(int x, int l) {
	auto& S = x > 0 ? rec3_pos : rec3_neg;
	while (!S.empty()) {
		//pos에서 찾기 : {l, 0}보다 크거나 같은 pair
		//neg에서 찾기 : {-l, 0}보다 크거나 같은 pair = 난이도가 -l이여도 번호는 항상 음수이므로 -l + 1에서부터 찾음
		auto iter = S.lower_bound({ l * x, 0 });
		if (iter == S.end()) {
			cout << -1 << '\n';
			return;
		}
		PII cur = *iter;
		if (is_valid(cur, x, 0)) {
			cout << cur.second * x << '\n';
			return;
		}

		S.erase(cur);
	}
}

void add() {
	int p, l, g;

	cin >> p >> l >> g;

	level[p] = l;
	group[p] = g;

	rec1_pos[g].push({ l, p });
	rec2_pos.push({ l, p });
	rec3_pos.insert({ l, p });

	rec1_neg[g].push({ -l, -p });
	rec2_neg.push({ -l, -p });
	rec3_neg.insert({ -l, -p });
}

void solve() {

	int N, M;
	cin >> N;
	while (N--)
		add();

	map<string, int> cmd = { {"recommend", 1},{"recommend2", 2},{"recommend3", 3},{"add", 4},{"solved",5} };
	int p, l, g, x;

	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		
		switch (cmd[str]) {
		case 1:
			cin >> g >> x;
			rec1(g, x);
			break;
		case 2:
			cin >> x;
			rec2(x);
			break;
		case 3:
			cin >> x >> l;
			rec3(x, l);
			break;
		case 4:
			add();
			break;
		case 5:
			cin >> p;
			level[p] = group[p] = 0;
			break;
		}
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