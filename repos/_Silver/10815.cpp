#define _CRT_SECURE_NO_WARNINGS
#define cmp(a,b) ((a) > (b) ? 1 : ((a) < (b) ? -1 : 0))

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bin_search(vector<int>& v, int n);

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> v;

	int i, temp;
	for (i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	vector<int> result;
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> temp;
		result.push_back(bin_search(v, temp));
	}
	for (i = 0; i < m; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}

int bin_search(vector<int>& v, int n) {
	int start = 0, end = v.size(), mid;
	int result = 0;
	while (start <= end && !result) {
		mid = (start + end) / 2;
		switch (cmp(v[mid], n)) {
			case 1:
				end = mid - 1;
				break;
			case 0:
				result = 1;
				break;
			case -1:
				start = mid + 1;
				break;
		}
	}
	return result;
}
