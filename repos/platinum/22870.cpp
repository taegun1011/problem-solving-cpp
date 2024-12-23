    #define _CRT_SECURE_NO_WARNINGS
    #include <bits/stdc++.h>
    using namespace std;

    #define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    #define PII pair<int, int>
    #define ll long long
    #define INF 1e9

    int N, M;

    vector<vector<PII>> graph;
    vector<bool> used;

    vector<int> dijkstra(int s, int e){
        vector<int> dist(N, INF);

        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({dist[s] = 0, s});

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            int w = cur.first, u = cur.second;
            if(dist[u] != w)
                continue;

            for(auto nxt : graph[u]){
                int v = nxt.first, uv = nxt.second;
                if(used[v])
                    continue;
                if(dist[v] > uv + w)
                    pq.push({dist[v] = uv + w, v});
            }
        }

        return dist;
    }

    void backtrack(int s, int e, vector<int>& dist, int cost){
        int cur = s;
        while(cur != e) {
            PII nxt = {INF, 0};
            for(auto p : graph[cur])
                if(dist[p.first] == cost - p.second)
                    nxt = min(nxt, p);
            
            cost -= nxt.second;
            used[nxt.first] = true;
            cur = nxt.first;
        }
    }

    void solve() {
        cin >> N >> M;
        graph = vector<vector<PII>>(N, vector<PII>());
        used = vector<bool>(N);

        int u, v, w;
        while(M--){
            cin >> u >> v >> w;
            graph[u - 1].push_back({v - 1, w});
            graph[v - 1].push_back({u - 1, w});
        }
        cin >> u >> v;
        vector<int> dist = dijkstra(v - 1, u - 1);
        int a = dist[u - 1];
        backtrack(u - 1, v - 1, dist, a);
        dist[v - 1] = dist[u - 1] = false;
        int b = dijkstra(v - 1, u - 1)[u - 1];

        cout << a + b << endl;
    }

    int main() {
        FASTIO;
        int TC = 1;
        //cin >> TC;
        while (TC--)
            solve();
    }