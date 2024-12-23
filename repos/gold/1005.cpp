#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
enum {single, sum};
#define get_max(a,b) {(a) > (b) ? (a) : (b)};

int tower_cost[2][1001] = { 0, }; //[0] : 비용, [1] : 합계
int tower_order[1001][1001] = { 0, };
int visited[1001] = { 0, }; //해당 타워의 최소 시간을 계산했는가?

void fill_table(int n);
void get_maximum(int i, int n);
void clear_table(int n) {
	int i, j;
	for (i = 0; i <= n; i++) {
		tower_cost[0][i] = tower_cost[1][i] = visited[i] = 0;
		for (j = 0; j <= n; j++)
			tower_order[i][j] = 0;
	}
}

int main() {
	int i;
	int t, n, k;
	cin >> t;
	int X, Y, target;
	while (t > 0) {
		t--;
		cin >> n >> k;
		for (i = 1; i <= n; i++) {
			cin >> tower_cost[single][i];
			tower_cost[sum][i] = tower_cost[single][i];
			tower_order[i][i] = 1;
		}
			

		for (i = 1; i <= k; i++) {
			cin >> X >> Y;
			tower_order[X][Y] = 1;
		}
		fill_table(n);
		cin >> target;
		cout << tower_cost[sum][target] << endl;

		clear_table(n);
	}
}

void fill_table(int n) {
	for (int i = 1; i <= n; i++) {
		if(!visited[i])
			get_maximum(i, n);
	}
}

void get_maximum (int i, int n) { //현재 열의 최대 비용을 계산
	int max = tower_cost[single][i], temp;
	int j;
	for (j = 1; j <= n; j++)
	{
		if (i == j) continue;
		if (tower_order[j][i]) {
			if (!visited[j])
				get_maximum(j, n);
			temp = tower_cost[single][i] + tower_cost[sum][j];
			max = get_max(temp, max);
		}
	}
	visited[i] = 1;

	tower_cost[sum][i] = max;
}