#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;

	list<int> L(N);
	int i = 1;
	list<int>::iterator iter;
	for (iter = L.begin(); iter != L.end(); iter++)
		*iter = i++;

	vector<int> ans;
	iter = L.begin();
	while (!L.empty()) {
		for (int i = 0; i < K - 1; i++) {
			iter++;
			if (iter == L.end())
				iter = L.begin();
		}
		if (iter == L.end())
			iter = L.begin();
		ans.push_back(*iter);

		iter = L.erase(iter);
		if (iter == L.end())
			iter = L.begin();
	}

	cout << '<';
	for (int i = 0; i < N - 1; i++)
		cout << ans[i] << ", ";
	cout << ans[N - 1] << ">\n";
}