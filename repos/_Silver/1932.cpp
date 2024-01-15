#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) (a) > (b) ? (a) : (b)
int find_max_sum(vector<vector<int>>, int size);

int main() {
	int n;
	cin >> n;

	vector<vector<int>> triangle;

	int temp;
	for (int i = 0; i < n; i++) {
		vector<int> row;
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		triangle.push_back(row);
	}

	cout<< find_max_sum(triangle, n) << endl;

	return 0;
}

int find_max_sum(vector<vector<int>> v, int n) {
	int** sum = new int* [n];
	for (int i = 0; i < n; i++) {
		sum[i] = new int[n];
	}

	sum[0][0] = v[0][0];
	int larger;
	for (int i = 1; i < n; i++) {
		sum[i][0] = sum[i - 1][0] + v[i][0];
		sum[i][i] = sum[i - 1][i - 1] + v[i][i];
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				larger = sum[i - 1][0];
			else if (j == i)
				larger = sum[i - 1][j - 1];
			else
				larger = max(sum[i - 1][j - 1], sum[i - 1][j]);
			sum[i][j] = larger + v[i][j];
		}
			
	}

	int max = 0;
	for (int i = 0; i < n; i++)
		if (max < sum[n - 1][i])
			max = sum[n - 1][i];

	return max;
}