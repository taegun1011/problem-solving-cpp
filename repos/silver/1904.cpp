#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int tile[1000001];
void setup();
void fill(int n);

int main() {
	int n;
	cin >> n;

	setup();
	fill(n);

	printf("%d\n", tile[n]);
}

void setup() {
	tile[0] = 1;
	tile[1] = 1;
}

void fill(int n) {
	int i;
	for (i = 2; i <= n; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 15746;
	}
}