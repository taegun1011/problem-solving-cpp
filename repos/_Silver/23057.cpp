#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
	set<int> S;
	//브루트포스, 새 값 들어올 때마다 set 원소 + 새 값을 S에 추가

	int N;
	cin >> N;

	int val, sum = 0;

	//초기 Set 생성
	for (int i = 0; i < N; i++) {
		cin >> val;
		set<int> temp;
		//계산결과를 저장할 임시 집합 temp

		for (int j : S)
			temp.insert(j + val);

		for (int j : temp)
			S.insert(j);

		S.insert(val);
		sum += val;
	}
	cout << sum - S.size() << endl;
	
}