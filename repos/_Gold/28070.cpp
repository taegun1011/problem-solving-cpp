#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define PII pair<int, int>

int main() {
	FASTIO
	int n;
	cin >> n;
	
	vector<PII> v[2];

	//ÀÔ·Â ¹× ÆÄ½Ì
	string date;
	int y, m;
	for (int i = 0; i < n; i++) {
		cin >> date;
		y = stoi(date);
		m = stoi(date.substr(5));
		v[0].push_back({ y,m });

		cin >> date;
		y = stoi(date);
		m = stoi(date.substr(5));
		v[1].push_back({ y,m });
	}

	vector<vector<int>> matrix(10000, vector<int>(13));

	int max = 0, max_y, max_m;
	for (int i = 0; i < n; i++) {
		for (int j = v[0][i].first; j <= v[1][i].first; j++) {
			for (int k = 1; k <= 12; k++) {
				if ((j == v[0][i].first && k < v[0][i].second) || (j == v[1][i].first && k > v[1][i].second))
					continue;
				matrix[j][k]++;
				if (matrix[j][k] > max) {
					max = matrix[j][k];
					max_y = j;
					max_m = k;
				}	
			}
		}
	}
	if(max_m < 10)
		cout << max_y << "-0" << max_m << endl;
	else
		cout << max_y << '-' << max_m << endl;
}