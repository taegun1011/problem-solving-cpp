#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int dp[301];
int moved[301] = { 0, };
int getMaxScore(int* &score, int n);

int main() {
	int n;
	std::cin >> n;
	int* score = new int[n + 1];
	int temp;
	for (int i = 1; i <= n; i++) {
		std::cin >> temp;
		score[i] = temp;
	}
	std::cout << getMaxScore(score, n) << std::endl;
}

int getMaxScore(int* &score, int n) {
	dp[1] = score[1];
	dp[2] = dp[1] + score[2];
	dp[3] = std::max(score[1], score[2]) + score[3];
	for (int i = 4; i <= n; i++) {
		dp[i] = std::max(score[i - 1] + dp[i - 3], dp[i - 2]) + score[i];
	}
	return dp[n];
}