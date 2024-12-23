#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

void DFS(int, int);
int findPath(int, int, int);

int point[100001] = { 0, };
int path[100001] = { 0, };

int main() {
	int n, k;
	cin >> n >> k;

	DFS(n, k);
	cout << findPath(n, k, 0) << endl;
}

void DFS(int n, int k) {
	stack<int> S;
	point[n] = 1;
	S.push(n);

	int cur_pos = n, next_pos;

	while (cur_pos != k) {
		printf("%d\n", cur_pos);

		//X-1
		if (cur_pos >= 1 && !point[cur_pos - 1]) {
			next_pos = cur_pos - 1;
			point[next_pos] = 1;
			S.push(next_pos);
			path[next_pos] = -1;

			cur_pos = next_pos;
			continue;
		}

		//X+1
		if (cur_pos <= 100000 && !point[cur_pos + 1]) {
			next_pos = cur_pos + 1;
			point[next_pos] = 1;
			S.push(next_pos);
			path[next_pos] = 1;

			cur_pos = next_pos;
			continue;
		}

		//X*2
		if (cur_pos <= 50000 && !point[cur_pos * 2]) {
			next_pos = cur_pos * 2;
			point[next_pos] = 1;
			S.push(next_pos);
			path[next_pos] = cur_pos;

			cur_pos = next_pos;
			continue;
		}

		cur_pos = S.top();
		S.pop();
	}
	
}

int findPath(int n, int k, int count) {
	if (n == k)
		return count;
	findPath(n, k - path[k], count + 1);
}