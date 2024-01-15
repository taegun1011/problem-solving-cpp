#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define graph vector<vector<int>>
#define INF 987654321

bool visited[11];
int N;
int minVal = INF;

void recursion(vector<int> price, graph& discount, int size, vector<int> v) {
	//순열 생성되면 총액 계산
	if (size == N) {
		int sum = 0;
		for (int i : v) {
			sum += price[i];
			for (int j = 1; j <= N; j++) {
				price[j] -= discount[i][j];
				if (price[j] <= 0)
					price[j] = 1;
			}
		}

		if (sum < minVal)
			minVal = sum;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			v.push_back(i);
			
			recursion(price, discount, size + 1, v);

			visited[i] = 0;
			v.pop_back();
		}
	}
}

int main() {
	cin >> N;

	vector<int> price(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> price[i];

	graph discount(N + 1, vector<int>(N + 1, 0));

	int E, u, v, w;
	for (u = 1; u <= N; u++) {
		cin >> E;
		for (int i = 1; i <= E; i++) {
			cin >> v >> w;
			discount[u][v] = w;
		}
	}

	recursion(price, discount, 0, vector<int> ());

	cout << minVal << endl;
}