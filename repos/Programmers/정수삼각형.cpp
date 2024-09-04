#include <string>
#include <vector>

using namespace std;

int N;
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    N = triangle.size();

    dp[0][0] = triangle[0][0];
    for(int i=0;i<N-1;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + triangle[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1]);
        }
    }
    
    int answer = 0;
    for(int i=0;i<N;i++)
        answer = max(answer, dp[N - 1][i]);
    return answer;
}