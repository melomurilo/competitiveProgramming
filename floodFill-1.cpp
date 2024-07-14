#include <bits/stdc+.h>
using namespace std;

#define MAXN 50
int n,m;
char grid[MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void floodFill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;

    grid[r][c] = 'T';

    for (int i = 0; i < 4; i++) {
        if (grid[r+dx[i]][c+dy[i]] == 'A') {
            floodfill(r+dx[i], c+dy[i]);
        }
    }
}


int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
}