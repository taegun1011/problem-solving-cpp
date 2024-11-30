#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> graph;

int diff(const string& a, const string& b){
    int len = a.size(), ret = 0;
    for(int i=0;i<len;i++)
        ret += (a[i] != b[i]);
    return ret;
}

int bfs(const string& begin, const string& end, const vector<string>& words){
    vector<bool> visited(N);
    queue<pair<int, int>> Q;
    
    for(int i=0;i<N;i++){
        if(diff(words[i], begin) == 1){
            visited[i] = true;
            Q.push({i, 1});
        }
    }
    
    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();
        
        int cur = p.first, cd = p.second;
        if(words[cur] == end)
            return cd;
        
        for(int nxt : graph[cur]){
            if(!visited[nxt]){
                visited[nxt] = true;
                Q.push({nxt, cd + 1});
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    N = words.size();
    graph = vector<vector<int>>(N, vector<int>());
    
    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){
            if(i == j)
                continue;
            if(diff(words[i], words[j]) == 1)
                graph[i].push_back(j);
        }
    }
    
    int answer = bfs(begin, target, words);
    return answer;
}