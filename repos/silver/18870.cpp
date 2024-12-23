#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> v;

	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> v_sorted(v);
	sort(v_sorted.begin(), v_sorted.end());
	v_sorted.erase(unique(v_sorted.begin(), v_sorted.end()), v_sorted.end());

	for (int i = 0; i < n; i++) {
		cout << lower_bound(v_sorted.begin(), v_sorted.end(), v[i]) - v_sorted.begin() << ' ';
	}
}