#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

bool decision(vector<int>& v, int i) {
	int l = 0, r = v.size() - 1;

	
	while (l < r) {
		if (v[l] + v[r] > v[i])
			r--;
		else if (v[l] + v[r] == v[i]) {
			//자기자신은 포함하면 안 됨
			if (r == i)
				r--;
			else if (l == i)
				l++;
			else
				return true;
		}
		else
			l++;
	}
	return false;
}

int main() {
	int N; cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	//배열을 오름차순으로 정렬
	sort(v.begin(), v.end());

	//각 원소에 대해 투포인터로 v[l] + v[r] = v[i] (l!=r)인지 확인한다

	vector<int> checked(N);
	for (int i = 0; i < N; i++) {
		if (decision(v, i))
			checked[i] = 1;
	}

	int res = 0;
	for (int i : checked)
		if (i == 1)
			res++;

	cout << res << endl;
}