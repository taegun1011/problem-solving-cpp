#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MAX 100000 + 5
int unused;
int nxt[MAX][10];
bool chk[MAX];

bool insert(string S) {
	// 1. 새 노드를 생성하지 않고 삽입을 마치는 경우
	// 2. 현재 위치가 표시가 돼있을 경우 

	int cur = 1;
	bool flag = false;

	for (char ch : S) {
		int type = ch - '0';
		if (chk[cur])
			return false;

		if (nxt[cur][type] == -1) {
			flag = true;
			nxt[cur][type] = unused++;
		}
		cur = nxt[cur][type];
	}

	chk[cur] = true;
	return flag;
}

void solve() {
	unused = 2;
	memset(nxt, -1, sizeof(nxt));
	memset(chk, 0, sizeof(chk));

	int N;
	cin >> N;

	string str;

	bool flag = true;
	while (N--) {
		cin >> str;
		if(flag)
			flag &= insert(str);
	}

	cout << (flag ? "YES" : "NO") << endl;
}

int main() {
	FASTIO;
	int TC;
	cin >> TC;
	while (TC--)
		solve();
}