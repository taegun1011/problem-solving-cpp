#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N, S, M;
vector<int> v;

map<int, int> dp[51];

//n이 0부터 M까지인가?
bool inRange(int n) {
	return n >= 0 && n <= M;
}

int solve() {
	dp[0][S]++;

	//dp[i-1]의 값을 순회하며 가능한 값은 모두 추가한다.
	for (int i = 1; i <= N; i++) {
		for (auto j : dp[i-1]) {
			if (inRange(j.first + v[i]))
				dp[i][j.first + v[i]]++;
			if (inRange(j.first - v[i]))
				dp[i][j.first - v[i]]--;
		}
		if (dp[i].empty())
			return -1;
	}

	int max = -1;
	for (auto i : dp[N])
		if (i.first > max)
			max = i.first;

	return max;
}

int main() {
	cin >> N >> S >> M;

	int val;
	v.push_back(-1);
	for (int i = 0; i < N; i++) {
		cin >> val;
		v.push_back(val);
	}

	cout << solve() << endl;
}

//점화식을 0,1 2개만 사용하는 것이 아니라 이전 값을 모두 저장하는 것이 핵심!
//값의 중복을 막기 위해 해쉬맵을 사용했으나 checked 배열을 사용해도 될 듯