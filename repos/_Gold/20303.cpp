#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N, M, K;
vector<int> p;
vector<int> w;
vector<int> v;

void make_set() {
	for (int i = 0; i < N; i++) {
		p.push_back(i);
		w.push_back(1);
		int c;
		cin >> c;
		v.push_back(c);
	}
}

int find(int x) {
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	int px = find(x), py = find(y);
	if (px != py) {
		p[py] = px;
		w[px] += w[py];
		v[px] += v[py];
	}
}

//각 집합의 root만 사용
vector<int> r;
int dp[3001];

int main() {
	FASTIO;
	cin >> N >> M >> K;

	//union find로 각 아이들이 속한 집합의 weight와 value를 계산
	make_set();
	while (M--) {
		int a, b;
		cin >> a >> b;
		merge(a - 1, b - 1);
	}

	for (int i = 0; i < N; i++)
		if (p[i] == i)
			r.push_back(i);

	for (int i = 0; i < r.size(); i++) {
		int weight = w[r[i]], value = v[r[i]];
		for (int j = K - 1; j >= weight; j--)
			dp[j] = max(dp[j], dp[j - weight] + value);
	}

	cout << dp[K - 1] << '\n';
}