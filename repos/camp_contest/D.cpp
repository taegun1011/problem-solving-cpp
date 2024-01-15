#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define PIS pair<int, string>

vector<PIS> v;

//천간
int CG[10][10];

//지지
int GG[12][12];

int cg(string a, string b) {
	return CG[a[0] - '0'][b[0] - '0'];
}

int gg(string a, string b) {
	return GG[a[1] - 'A'][b[1] - 'A'];
}

int getSum(PIS a, PIS b) {
	return cg(a.second, b.second) + gg(a.second, b.second);
}

int getTripleSum(PIS a, PIS b, PIS c) {
	return getSum(a, b) + getSum(b, c) + getSum(c, a) + a.first + b.first + c.first;
}

int N;

void solve() {
	//1000000C3 == 10^18 너무 오래걸림

	//한번에 확인 가능한가? 투 포인터
	int res = getTripleSum(v[0], v[1], v[2]);
	vector<PIS> ans = { v[0], v[1], v[2] };

	//현재 팀원 중 둘과 새 사람의 조합을 비교
	for (int i = 3; i < N; i++) {
		vector<PIS> temp(ans);
		for (int j = 0; j < 3; j++) {
			int idx1 = (j + 1) % 3, idx2 = (j + 2) % 3;

			//새 사람
			if (res < getTripleSum(temp[idx1], temp[idx2], v[i])) {
				ans[j] = v[i];
				res = getTripleSum(temp[idx1], temp[idx2], v[i]);
			}
		}
	}

	//아까 사람이 궁합이 최대일 수도 있다

	cout << res << endl;
}

int main() {
	FASTIO;
	cin >> N;

	//입력
	for (int i = 0; i< 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> CG[i][j];

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			cin >> GG[i][j];

	int n; string str;
	for (int i = 0; i < N; i++) {
		cin >> n >> str;
		v.push_back({ n,str });
	}

	solve();
}