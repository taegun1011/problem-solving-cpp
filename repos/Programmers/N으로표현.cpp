#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    set<int> dp[9];

    int x = N;
    for (int i = 1; i <= 8; i++) {
        dp[i] = set<int>();
        dp[i].insert(x);
        x = x * 10 + N;
    }

    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int a : dp[j])
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b)
                        dp[i].insert(a / b);
                }
        }
    }

    for (int i = 1; i <= 8; i++)
        if (dp[i].count(number))
            return i;

    return -1;
}