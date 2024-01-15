#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define MAX 246912

bool checked[MAX * 2 + 1];
void eratosthenes() {
	int i, j, limit = sqrt(INT_MAX);
	for (i = 2; i <= MAX; i++) {
		if (!checked[i] && i <= limit) {
			for (j = i * i; j <= MAX; j += i)
				checked[j] = 1;
		}
	}
	checked[0] = checked[1] = 1;
}

int main() {
	eratosthenes();

	int n;
	cin >> n;
	while (n) {		
		cout << count(checked + n + 1, checked + n * 2 + 1, false) << endl;

		cin >> n;
	}

}