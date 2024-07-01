#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

void knapSack(int W, int wt[], int vl[], int n) {

    // linhas são os items, colunas os pesos;
    vector<vector<int>> K(n+1, vector<int>(W+1));

    // preenche as tabelas com o value máximo permitido na matriz;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
                // se o peso do meu item for suficiente nesse coluna, ele é inserido. Senão, é o value acima.
            } else if (wt[i-1] <= j) {
                // o max entra o value na linha acima, ou o value do item+ o value do item acima menos o peso do meu item.
                K[i][j] = max(K[i-1][j], vl[i-1]+K[i-1][j-wt[i-1]]);
            } else {
                K[i][j] = K[i-1][j];
            }
        }
    }

    // maior value possivel:
    int ans = K[n][W];
    cout << "Value máximo: " << ans << "\n";

    // para printar os itens colocados na mochila:

    int j = W;
    vector<int> pesoEscolhido;

    for (int i = n; i > 0 && ans > 0; i--) {
        if (ans == K[i-1][j]) {continue;}
        else {
            pesoEscolhido.push_back(wt[i-1]);
            ans -= vl[i-1];
            j -= wt[i-1];
        }
    }

    cout << "\nPesos escolhidos:\n";
    for (int u : pesoEscolhido) {
        cout << u << endl;
    }

}

int main() {

    int pesos[] = {2, 3, 4, 5};
    int values[] = {1, 2, 5, 6};
    int capacidade = 8;
    int n = sizeof(pesos)/sizeof(pesos[0]);
    knapSack(capacidade, pesos, values, n);

}