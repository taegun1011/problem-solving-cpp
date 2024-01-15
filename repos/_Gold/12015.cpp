#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> v;
int N;

void LIS() {
	vector<int> lis;
	lis.push_back(v[0]);

	for (int i = 1; i < N; i++) {
		//매번 v[i]가 들어갈 수 있는 위치를 찾는다
		//원래 위치의 값보다 v[i]가 작으면 바꿔준다
		//위치를 발견하지 못했을 경우 맨 끝에 추가한다
		vector<int>::iterator pos = lower_bound(lis.begin(), lis.end(), v[i]);
		if (pos == lis.end())
			lis.push_back(v[i]);
		else
			lis[pos - lis.begin()] = v[i];
	}

	cout << lis.size() << endl;
}

int main() {
	FASTIO;

	cin >> N;
	
	v.resize(N);
	for (int& i : v)
		cin >> i;

	LIS();
}

//LIS라고 dp로 풀어야하는 건 아니다
//O(N log N) 풀이
//'직접 LIS를 만든다'라는게 포인트