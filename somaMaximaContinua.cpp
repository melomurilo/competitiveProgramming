#include <bits/stdc++.h>
using namespace std;

// O(n)
int kadane(vector<int> nums) {
    int sz = nums.size();
    int sum = 0, best = 0;
    for (int i = 0; i < sz; i++) {
        sum = max(nums[i], sum+nums[i]);
        best = max(best, sum);
    }
    return best;
}

// O(n^2)
int kdn(vector<int> nums) {
    int sz = nums.size();

    int best = 0;
    for (int i = 0; i < sz; i++) {
        int sum = 0;
        for (int j = i; j < sz; j++) {
            sum += nums[j];
            best = max(best, sum);
        }
    }
    return best;
}


int main() {
    vector<int> n = {-1, 2, 4, -3, 5, 2, -5, 2};

    cout << kadane(n) << '\n';
    cout << kdn(n) << '\n';
}
