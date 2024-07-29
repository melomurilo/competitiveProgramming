#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> tiii;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0); for (int i = 0 ; i < n; i++) p[i] = i;
        rank.assign(n, 0);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return (findSet(i) == findSet(j));
    }

    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if (x == y) return;

        if (rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

int main() {
    int V,E; cin >> V >> E;
    vector<tiii> EL(E);

    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        EL[i] = {w,u, v};
    }
    sort(EL.begin(), EL.end());

    int mst_cost = 0, num_taken = 0;
    UnionFind UF(V);

    for (auto &[w, u, v] : EL) {
        if (UF.isSameSet(u, v)) continue;
        mst_cost += w;
        UF.unionSet(u,v);
        ++num_taken;
        if (num_taken == V-1) break;
    }
    cout << mst_cost << '\n';
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