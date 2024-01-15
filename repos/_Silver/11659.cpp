#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int getInterval(const vector<int>& sum, int start, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size, count, num;
	cin >> size >> count;

	while (size > 0) {
		size--;
		cin >> num; v.push_back(num);
	}

	//sum[i] = v의 앞에서부터 i개 원소의 합
	vector<int> sum(v.size() + 1);
	sum[0] = 0;

	for (int i = 1; i < sum.size(); i++)
		sum[i] = sum[i - 1] + v[i - 1];
	

	int i, j;
	while (count > 0) {
		count--;
		cin >> i >> j;
		cout << getInterval(sum, i, j) << '\n';
	}
}

int getInterval(const vector<int>& sum, int start, int end) {
	return sum[end] - sum[start - 1];
}