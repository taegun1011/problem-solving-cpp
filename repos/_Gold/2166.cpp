#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

bool comp(pair<ll, ll>p1, pair<ll, ll>p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first > p2.first;
}

int main() {
	FASTIO;

	int N; cin >> N;
	vector<pair<ll, ll>> coord(N);
	for(auto& p : coord)
		cin >> p.first >> p.second;

	ll top = 0, bot = 0;
	for (int i = 0; i < N ; i++) {
		top += coord[i].first * coord[(i + 1) % N].second;
		bot += coord[i].second * coord[(i + 1) % N].first;
	}

	double result = 0.5 * abs(top - bot);
	printf("%.1f\n", result);
}