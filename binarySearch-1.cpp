#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> nums({1, 2, 3, 4, 5, 10, 12, 21, 33});
    // sorted array

    int l = 0, r = nums.size()-1;
    int target = 12;
    int ans = -1;

    while (l <= r) {
        int mid = l+(r-l)/2;

        if (nums[mid] == target) {ans = mid;}

        if (target > mid) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    // index que está o target:
    cout << ans << '\n';
}