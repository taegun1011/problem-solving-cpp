#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

//사실 전체 개수는 10C1 + 10C2 + ... + 10C10 = 2^10 - 1 (10C0)
ll arr[1000001];
int nxt = 1;

//길이 len의 줄어드는 수 부터 센다
void recur(int len, ll num) {
	if (len == 0) {
		arr[nxt++] = num;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (num == -1)
			recur(len - 1, i);
		else if (num % 10 > i)
			recur(len - 1, num * 10 + i);
	}
}

void solve() {
	memset(arr, -1, sizeof(arr));
	for (int i = 1; i <= 10; i++) 
		recur(i, -1);

	int N;
	cin >> N;
	cout << arr[N] << '\n';
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}