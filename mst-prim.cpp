#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

vector<vii> AL;
vi taken;
priority_queue<pii> pq;

void process(int u) {
    taken[u] = 1;
    for (auto &[v, w] : AL[u]) {
        if (!taken[v]) {
            pq.emplace(-w, -v);
        }
    }
}

int main() {

    int V, E; cin >> V >> E;
    AL.assign(V, vii());
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        AL[u].emplace_back(v,w);
        AL[v].emplace_back(u,w);
    }
    taken.assign(V, 0);
    process(0);
    int mst_cost = 0, num_taken = 0;

    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        w = -w; u = -u;
        if (taken[u]) continue;
        mst_cost += w;
        process(u);
        ++num_taken;
        if (num_taken == V-1) break;
    }
    printf("MST cost = %d (Prim’s)\n", mst_cost);
}

/*

5 7
0 1 4
0 2 4
0 3 6
0 4 6
1 2 2
2 3 8
3 4 9

 */