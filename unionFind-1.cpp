// Implementacao do CP Steve Halim

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank, sizeSet;
public:
    UnionFind(int n) {
        p.assign(n, 0); for (int i = 0; i < n; i++) {p[i] = i;}
        rank.assign(n, 0);
        sizeSet.assign(n, 1);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    void unionSet(int i, int j) {
        int x = findSet(i);
        int y = findSet(j);
        if (x == y) return;

        if (rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        sizeSet[y] += sizeSet[x];
    }
};

int main() {
    int n = 5;
    UnionFind UF(n);
    UF.unionSet(0,1);
    UF.unionSet(2,3);
    UF.unionSet(4,3);
    UF.unionSet(1,3);
    // Halim UFDS
}