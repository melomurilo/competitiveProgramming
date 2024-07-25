#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

/* DAG
8
5
0 1
2 1
1 5
7 4
4 6
*/

/*
 ans = 0 2 1 3 5 7 4 6 
*/

vector<int> adj[MAXN];

typedef vector<int> vi;

int main() {

    int n, m; cin >> n >> m;
    queue<int> filaPrint;

    vi grau(n, 0);
    priority_queue<int, vi, greater<int>> pq;

    while (m--) {
        int x,y; cin >> x >> y;

        // tarefa x tem que ser executada antes do y;
        grau[y]++;
        adj[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        if (grau[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        for (auto v : adj[u]) {
            --grau[v];
            if (grau[v] > 0) continue;
            pq.push(v);
        }
        filaPrint.push(u);
    }

    // se a fila nao tiver a mesma quantidade de vertices/nodes,
    // sabemos que não é possível realizar o procedimento ordenado.

    // Se, ao final do processo, ainda sobrarem vértices, há um ciclo e não há ordem para resolver o problema. Caso contrário, o problema está resolvido! (noic)

    if (filaPrint.size() < n) {
        cout << "impossivel\n";
    } else {
        while (!filaPrint.empty()) {
            cout << filaPrint.front() << ' '; filaPrint.pop();
        }
    }
}