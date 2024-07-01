#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

vector<int> adj[MAXN];
int visited[MAXN];


int main() {

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int dist[MAXN];
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = true;

    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            dist[u] = dist[s]+1;
            q.push(u);
        }
    }
}