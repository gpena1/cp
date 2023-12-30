#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    // attempting to implement edmonds karp algorithm for calculating maximum network flow
    vector<vector<int>> outneighborhood(n, vector<int>());
    vector<vector<int>> inneighborhood(n, vector<int>());
    vector<vector<vector<ll>>> flow(n, vector<vector<ll>>(n, {0,-1}));
    for(int i=0;i<m;++i){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        outneighborhood[a].push_back(b);
        inneighborhood[b].push_back(a);
        flow[a][b][1] = c;
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
                if(flow[cur][k][1] - flow[cur][k][0] > 0 && predecessors[k] == -1){
                    predecessors[k] = cur;
                    dq.push_back(k);
                }
            }
            for(auto &k:inneighborhood[cur]){
                if(flow[k][cur][0] > 0 && predecessors[k] == -1){
                    predecessors[k] = cur;
                    dq.push_back(k);
                }
            }
        }
        if(!end_reached) break;
        int cur = t;
        ll bottleneck = INT64_MAX;
        while(predecessors[cur] != cur){
            int a = predecessors[cur];
            // a backedge was taken
            if(flow[a][cur][1] == -1)
                bottleneck = min(bottleneck, flow[cur][a][0]);
            else
                bottleneck = min(bottleneck, flow[a][cur][1] - flow[a][cur][0]);

            cur = a;
        }

        cur = t;
        while(predecessors[cur] != cur){
            int a = predecessors[cur];
            // a backedge was taken
            if(flow[a][cur][1] == -1)
                flow[cur][a][0] -= bottleneck;
            else
                flow[a][cur][0] += bottleneck;

            cur = a;
        }
    }
    ll max_flow = 0;
    for(auto &k: inneighborhood[t]) {
        max_flow += flow[k][t][0];
    }
    vector<vector<ll>> edges_used;
    for(int i=0;i<n;++i){
        for(auto &k:outneighborhood[i]){
            if(flow[i][k][0])
                edges_used.push_back({i,k,flow[i][k][0]});
        }
    }
    cout<<n<<" "<<max_flow<<" "<<edges_used.size()<<'\n';
    for(auto &edge:edges_used){
        cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<'\n';
    }
}