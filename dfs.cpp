#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int visited[MAXN];
vector<int> adj[MAXN];

void dfs(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (auto u : adj[n]) {
        dfs(u);
    }
}

int main() {

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

}