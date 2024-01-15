#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void eratosthenes(int N) {
	long long i, j;
	vector<bool> checked(N + 1);

	for (i = 2; i <= N; i++) {
		if (!checked[i]) {
			prime.push_back(i);
			for (j = i * i; j <= N; j += i)
				checked[j] = 1;
		}
	}
}

int main() {
	int N; cin >> N;

	//N 이하의 소수를 어쩌구의 체를 통해 저장한다
	eratosthenes(N);

	int start = 0, end = prime.size() - 1, mid = (start + end) / 2, rans;
	bool ans;
	//이분 탐색을 통해 정확한 i를 구한다
	while (start <= end) {
		cout << "? " << prime[mid] << endl;
		cout << flush;
		cin >> ans;
		//왼쪽 탐색 : 0이 나올 경우
		if (ans == 0) {
			end = mid - 1;
			rans = mid;
		}

		//오른쪽 탐색 : 1이 나올 경우
		else
			start = mid + 1;
		mid = (start + end) / 2;
	}
	cout << "! " << prime[rans] << endl;
	cout << flush;
}