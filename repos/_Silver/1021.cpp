#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

deque<int> D;
void left() {
	D.push_back(D.front());
	D.pop_front();
}

void right() {
	D.push_front(D.back());
	D.pop_back();
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;

	vector<int> v(M);
	for (int& i : v)
		cin >> i;

	for (int i = 1; i <= N; i++)
		D.push_back(i);

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int size = D.size();

		//v[i]가 위치한 위치
		int pos = find(D.begin(), D.end(), v[i]) - D.begin() + 1;
			
		//pos가 1이 될 때까지 옮겨야 하는 횟수
		//left => pos - 1
		//right => size - pos + 1

		if (pos - 1 < size - pos + 1) {
			cnt += pos - 1;
			for (int j = 0; j < pos - 1; j++)
				left();
		}

		else {
			cnt += size - pos + 1;
			for (int j = 0; j < size - pos + 1; j++)
				right();
		}
	
		D.pop_front();
	}

	cout << cnt << endl;
}