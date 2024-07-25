#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

/* DAG
8
8
0 1
0 2
1 3
1 2
2 3
3 4
2 5
7 6
*/

/*
 ans = 7 6 0 1 2 5 3 4
 */

vector<int> adj[MAXN];
vector<bool> visited;

vector<int> ts;

void toposort(int s) {
    visited[s] = true;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            toposort(u);
        }
    }
    ts.push_back(s);
}

int main() {

    int n, m; cin >> n >> m;

    visited.assign(n, false);
    ts.clear();

    while (m--) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            toposort(i);
        }
    }
    reverse(ts.begin(), ts.end());

    for (int k : ts) {
        cout << k << ' ';
    }
    cout << '\n';
}