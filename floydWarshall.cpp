#include <bits/stdc++.h>
using namespace std;

const int MAXN = 450; // evitar caso > 450;
const int INF = 1e9;

int AM[MAXN][MAXN];

int main() {

    int V, E; cin >> V >> E;

    // inicializando adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            AM[i][j] = INF;
            AM[i][i] = 0;
        }
    }

    while(E--) {
        int i,j, w; cin >> i >> j >> w;
        AM[i][j] = w;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);
            }
        }
    }


    // CP4
    for (int u = 0; u < V; ++u)
        for (int v = 0; v < V; ++v)
            printf("APSP(%d, %d) = %d\n", u, v, AM[u][v]);
}

/*
// Graph in Figure 4.30
5 9
0 1 2
0 2 1
0 4 3
1 3 4
2 1 1
2 4 1
3 0 1
3 2 3
3 4 5
*/