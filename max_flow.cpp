#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<vector<int>> G;
ll capacities[501][501], flow[501][501];
int level[501];
bool dead[501];
bool visited[501];
int n;

// The following is an implementation of Dinic's algorithm.
// The source and sink are assumed to be nodes 1 and n, respectively,
// and the nodes all take on values between 1 and n inclusive.

ll dfs(int u, ll bottleneck) {
    if (u == n) return bottleneck;
    for (auto &v : G[u]) {
        if (level[v] != level[u] + 1) continue;
        if (capacities[u][v] - flow[u][v] <= 0) continue;
        if (dead[v]) continue;
        if (ll result = dfs(v, min(bottleneck, capacities[u][v] - flow[u][v]))) {
            flow[u][v] += result;
            flow[v][u] -= result;
            return result;
        }
    }
    dead[u] = true;
    return 0;
}
 
ll blocking_flow() {
    memset(level, -1, sizeof(level));
    memset(dead, 0, sizeof(dead));
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(1);
    level[1] = 0;
    visited[1] = 1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (!visited[v] && capacities[u][v] - flow[u][v] > 0) {
                level[v] = level[u] + 1;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
 
    if (level[n] == -1) return 0; 
    ll total_flow = 0;
    while (ll added = dfs(1, LLONG_MAX)) total_flow += added;
    return total_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int m;
    cin >> n >> m;
    G.assign(n + 1, vector<int>());
 
    memset(capacities, 0, sizeof(capacities));
    memset(flow, 0, sizeof(flow));
 
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        capacities[a][b] += c;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    ll max_flow = 0;
    while (ll added_flow = blocking_flow()) {
        max_flow += added_flow;
    }
 
    cout << max_flow << '\n';
}
