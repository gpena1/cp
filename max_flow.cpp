#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    // attempting to implement edmonds karp algorithm for calculating maximum network flow
    vector<unordered_set<int>> outneighborhood(n, unordered_set<int>());
    vector<unordered_set<int>> inneighborhood(n, unordered_set<int>());
    vector<vector<ll>> flow(n, vector<ll>(n, 0));
    vector<vector<ll>> capacities(n, vector<ll>(n, INT64_MAX));
    for(int i=0;i<m;++i){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        outneighborhood[a].insert(b);
        inneighborhood[b].insert(a);
        capacities[a][b] = c;
    }
    while(1){
        deque<int> dq;
        vector<int> predecessors(n,-1);
        predecessors[s] = s;
        dq.push_back(s);
        bool end_reached = false;
        while(!dq.empty()){
            int cur = dq.front();
            if(cur == t){
                end_reached = true;
                break;
            }
            dq.pop_front();
            for(auto &k:outneighborhood[cur]){
                if(flow[cur][k] < capacities[cur][k] && predecessors[k] == -1){
                    predecessors[k] = cur;
                    dq.push_back(k);
                }
            }
            for(auto &k:inneighborhood[cur]){
                if(flow[k][cur] > 0 && predecessors[k] == -1) {
                    predecessors[k] = cur;
                    dq.push_back(k);
                }
            }
        }
        if(!end_reached) break;
        int cur = t;
        ll bottleneck = INT64_MAX;
        while(predecessors[cur] != cur){
            int parent = predecessors[cur];
            // backedge taken
            if(!outneighborhood[parent].count(cur))
                bottleneck = min(bottleneck, flow[cur][parent]);
            else
                bottleneck = min(bottleneck, capacities[parent][cur] - flow[parent][cur]);

            cur = parent;
        }
        assert(bottleneck > 0);
        cur = t;
        while(predecessors[cur] != cur){
            int parent = predecessors[cur];

            flow[parent][cur] += bottleneck;
            flow[cur][parent] -= bottleneck;

            cur = parent;
        }
    }
    ll max_flow = 0;
    for(auto &k:inneighborhood[t]){
        max_flow += flow[k][t];
    }
    vector<vector<ll>> edges_used;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(flow[i][j] > 0){
                edges_used.push_back({i,j,flow[i][j]});
            }
        }
    }
    cout<<n<<" "<<max_flow<<" "<<edges_used.size()<<'\n';
    for(auto &edge:edges_used){
        cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<'\n';
    }
    return 0;
}