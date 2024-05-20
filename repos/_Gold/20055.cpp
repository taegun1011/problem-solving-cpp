#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int N;

vector<int> arr;
vector<bool> visited;

void print() {
	cout << "BELT : ";
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << "\n       ";
	for (int i = 2 * N - 1; i >= N; i--)
		cout << arr[i] << ' ';
	cout << endl;

	cout << "ROBOT : ";
	for (bool b : visited)
		cout << b << ' ';
	cout << endl << endl;
}

void rotate() {
	for (int i = N - 1; i > 0; i--)
		swap(visited[i], visited[i - 1]);

	for (int i = 2 * N - 1; i > 0; i--)
		swap(arr[i], arr[i - 1]);
	
	visited[N - 1] = 0;
}

void move_all() {
	for (int i = N - 1; i > 0; i--) {
		//visited[i]를 확인하지 않으면 다음칸 로봇이 움직이지 못했는데도 현재칸 로봇을 한칸 옮기는 문제가 발생한다
		if (arr[i] && visited[i - 1] && !visited[i]) {
			arr[i]--;
			visited[i] = 1;
			visited[i - 1] = 0;
		}
	}

	visited[N - 1] = 0;
}

void solve() {
	int K;
	cin >> N >> K;

	arr = vector<int>(N * 2);
	visited = vector<bool>(N);
	for (int& x : arr)
		cin >> x;

	int ans = 0;

	do {
		ans++;
		rotate();
		move_all();
		
		if (arr[0]) {
			arr[0]--;
			visited[0] = 1;
		}
		
		int cnt = 0;
		for (int x : arr)
			cnt += !x;

		if (cnt >= K)
			break;

	} while (1);

	cout << ans << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}