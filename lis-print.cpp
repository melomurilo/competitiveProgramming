// Longest Increasing Subsequence (LIS)
#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> arr) {
    int n = arr.size();

    vector<int> len;
    int insertedAt[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (len.empty() || len.back() < arr[i]) {
                len.push_back(arr[i]);
                insertedAt[i] = len.size()-1;
            } else {
                auto it = lower_bound(len.begin(), len.end(), arr[i]);
                *it = arr[i];
                insertedAt[i] = it-len.begin();
            }
        }
    }
    cout << "Valor máximo:\n";
    cout <<  len.size();

    // printando os valores:
    vector<int> final_len;
    int currentLength = len.size()-1;

    for (int i = n-1; i >= 0; i--) {
        if (insertedAt[i] == currentLength) {
            final_len.push_back(arr[i]);
            currentLength--;
        }
    }
    reverse(final_len.begin(), final_len.end());
    for (auto u : final_len) {
        cout << u;
    }
}

int main() {

}