#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) (a)>(b) ? (a) : (b)

int max_sum(vector<int> v, int n);

int main() {
	vector<int> v;
	int n;
	cin >> n;

	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	cout << max_sum(v, n) << endl;

	return 0;
}

int max_sum(vector<int> v, int n) {
	int M = v[0], sum = 0;
	for (int i = 0; i < n; i++) {
		sum = max(sum + v[i], v[i]);
		M = max(sum, M);
	}

	return M;
}
