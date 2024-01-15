#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int N;

bool visited[61][61][61];
int atk[61][61][61];

vector<int> attack(vector<int> v, int type) {
	vector<int> v2(v);

	switch (type) {
	case 1:
		v2[0] -= 9; v2[1] -= 3; v2[2] -= 1;
		break;
	case 2:
		v2[0] -= 9; v2[2] -= 3; v2[1] -= 1;
		break;
	case 3:
		v2[1] -= 9; v2[0] -= 3; v2[2] -= 1;
		break;
	case 4:
		v2[1] -= 9; v2[2] -= 3; v2[0] -= 1;
		break;
	case 5:
		v2[2] -= 9; v2[0] -= 3; v2[1] -= 1;
		break;
	case 6:
		v2[2] -= 9; v2[1] -= 3; v2[0] -= 1;
		break;
	}
	for (int& i : v2)
		if (i < 0)
			i = 0;

	return v2;
}

int BFS(vector<int> v) {
	queue<vector<int>> Q;
	Q.push(v);

	vector<int> cur;
	while (!Q.empty()) {
		cur = Q.front();
		Q.pop();
		for (int i = 1; i <= 6; i++) {
			vector<int> next = attack(cur, i);
			
			if (!visited[next[0]][next[1]][next[2]]) {
				Q.push(next);
				visited[next[0]][next[1]][next[2]] = 1;
				atk[next[0]][next[1]][next[2]] = atk[cur[0]][cur[1]][cur[2]] + 1;
			}
		}
	}

	return atk[0][0][0];
}

int main() {
	cin >> N;
	
	vector<int> v(3);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	cout << BFS(v) << endl;
}