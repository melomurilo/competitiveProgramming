// 2024-07-31 16:13:59
// time 110ms

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 450; // evitar caso > 450;
const int INF = 1e9;

vector<vector<int>> AM(MAXN, vector<int>(MAXN, INF));

int main() {

    int a, b, t = 1;
    set<int> s;
    int x = -1, y = -1;
    while(cin >> a >> b) {
        if (a == 0 and b == 0) {
            if (s.size() == 0) return 0;
            for (int k : s) {
                for (int i : s) {
                    for (int j : s) {
                        AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);
                    }
                }
            }

            int qnt = (s.size()-1)*s.size();
            int sum = 0;

            for (int i : s) {
                for (int j : s) {
                    sum+= AM[i][j];
                }
            }


            cout << "Case " << t++ << ": average length between pages = " << fixed << setprecision(3) << (double)sum/(double)qnt << " clicks"  <<'\n';
            AM.assign(MAXN, vector<int>(MAXN, INF));
            s.clear();
        } else {
            AM[a][b] = 1;
            AM[a][a] = 0;
            AM[b][b] = 0;
            s.emplace(a);
            s.emplace(b);
        }
    }
}
