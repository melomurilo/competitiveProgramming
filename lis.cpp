// Longest Increasing Subsequence (LIS)
#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> arr) {
    int n = arr.size();

    vector<int> len;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (len.empty() || len.back() < arr[i]) {
                len.push_back(arr[i]);
            } else {
                auto it = lower_bound(len.begin(), len.end(), arr[i]);
                *it = arr[i];
            }
        }
    }

    return len.size();
}

int main() {
    
}