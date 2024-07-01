// Longest Common Subsequence (LCS)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int lcs(string A, string B) {
    int n = A.size(), m = B.size();

    vector<vector<int>> K(n+1, vector<int>(m+1));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (A[i-1] == B[j-1]) {
                K[i][j] = 1+K[i-1][j-1];
            } else {
                K[i][j] = max(K[i-1][j], K[i][j-1]);
            }
        }
    }


    cout << "Maior valor: " << K[n][m] << "\n";
    // return K[n][m];

    // printar os valores:

    int index = K[n][m];
    vector<char> valores;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i-1] == B[j-1]) {
            valores.push_back(A[i-1]);
            i--;
            j--;
        } else if (K[i-1][j] > K[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "Letras iguais:\n";
    for (char c : valores) {
        cout << c << "\n";
    }
}

int main() {

    string str1 = "stone", str2 = "longest";
    lcs(str1, str2);
}