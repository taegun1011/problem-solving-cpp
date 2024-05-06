#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

string str;
int N;
vector<string> res;

void recur(int idx, string cur, stack<bool> S) {
	if (idx == N) {
		if (cur != str)
			res.push_back(cur);
		return;
	}

	if (str[idx] == '(') {
		cur.push_back('(');
		S.push(1);
		recur(idx + 1, cur, S);
		cur.pop_back();
		S.pop();
		S.push(0);
	}
	else if (str[idx] == ')') {
		if (!S.empty()) {
			if(S.top())
				cur.push_back(')');
			S.pop();
		}
	}
	else
		cur.push_back(str[idx]);
	recur(idx + 1, cur, S);
}

void solve() {
	cin >> str;
	N = str.length();

	recur(0, "", stack<bool>());
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (string r : res)
		cout << r << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}