#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(pair<int, int>a, pair<int, int>b) { //종료시간 - 시작시간 기준으로 오름차순 정렬
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int greedy(vector<pair<int, int>>& time, int n);

int main() {
	int n;
	cin >> n;

	int start, end;
	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		time.emplace_back(start, end);
	}

	sort(time.begin(), time.end(), myCompare);

	cout << greedy(time, n) << endl;
}

int greedy(vector<pair<int, int>>& time, int n) {
	int count = 0, current_time = 0;
	for (int i = 0; i < n; i++) {
		if (current_time <= time[i].first) {
			count++;
			current_time = time[i].second;
		}
	}
	return count;
}