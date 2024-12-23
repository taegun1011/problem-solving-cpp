#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

void solve(vector<char> v, int N) {
	string res = "";

	int start = 0, end = v.size() - 1;
	while (start <= end) {
		if (v[start] < v[end])
			res += v[start++];

		//같을 경우, 다른 문자가 나올때까지 진행한 뒤 더 작은 문자가 나오는 쪽부터 추가
		else if (v[start] == v[end]) {
			int start2 = start, end2 = end;
			while (v[start2] == v[end2] && start2 < end2) {
				start2++;
				end2--;
			}
				
			if(v[start2] < v[end2])
				res += v[start++];
			else
				res += v[end--];
		}

		else
			res += v[end--];
		//80, 161, 242,...마다 개행문자를 추가
		if (res.length() >= 80 && (res.length() - 80) % 81 == 0)
			res += '\n';
	}
	cout << res << endl;
}

int main() {
	int N;
	cin >> N;

	vector<char> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	solve(v, N);
}