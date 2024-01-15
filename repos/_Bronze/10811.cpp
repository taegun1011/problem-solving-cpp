	#define _CRT_SECURE_NO_WARNINGS
	#include <bits/stdc++.h>
	using namespace std;

	#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

	int main() {
		FASTIO;

		int N, M;
		cin >> N >> M;

		vector<int> v(N); 
		for (int i = 0; i < N; i++)
			v[i] = i + 1;

		int s, e;
		while (M) {
			M--;
			cin >> s >> e;

			reverse(v.begin() + s - 1, v.begin() + e);
		}

		for (int i : v)
			cout << i << ' ';
		cout << endl;
	}