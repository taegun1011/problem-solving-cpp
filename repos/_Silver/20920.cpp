#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		if (a.first.length() == b.first.length())
			return a.first.compare(b.first) < 0 ? true : false;
		else
			return a.first.length() > b.first.length();
	}
	else
		return a.second > b.second;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<string, int> dic;
	string temp;
	int count;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp.length() < m) continue;

		if ((count = dic.count(temp)) == 0 ) {
			dic.insert({ temp, 1 });
		}

		else {
			cout << temp << count << '\n';
			dic[temp]++;
		}

	}

	vector<pair<string, int>> ordered_dic;
	for (auto item : dic)
		ordered_dic.push_back(item);
	
	sort(ordered_dic.begin(), ordered_dic.end(), compare);

	for (vector<pair<string, int>>::iterator iter = ordered_dic.begin(); iter != ordered_dic.end(); iter++)
		cout << (*iter).first << '\n';
}