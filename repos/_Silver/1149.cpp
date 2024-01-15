#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define min(a,b) ((a)<(b) ? (a) : (b))

int GetMinimumCost(vector<vector<int>>& v, int n);

int main() {
	int n;
	cin >> n;

	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			int cost;
			cin >> cost;
			temp.push_back(cost);
		}
		v.push_back(temp);
	}

	cout << GetMinimumCost(v, n) << endl;
}

int GetMinimumCost(vector<vector<int>>& v, int n) {
	enum { R, G, B };

	//sum[i][color] = i번째 color색 건물까지 짓는 비용의 합
	int** sum = new int* [n];
	for (int i = 0; i < n; i++) {
		sum[i] = new int[3];
	}
	for (int i = R; i <= B; i++)
		sum[0][i] = v[0][i];

	int min, temp;

	for (int i = 1; i < n; i++) {
		for (int j = R; j <= B; j++) {
			min = 987654321;
			for (int k = R; k <= B; k++) {
				if (k != j) {
					temp = sum[i - 1][k];
					if (min > temp)
						min = temp;
				}
			}
			sum[i][j] = min + v[i][j];
		}
	}

	return min(min(sum[n - 1][R], sum[n - 1][G]), sum[n - 1][B]);
}