#include <bits/stdc++.h>
using namespace std;

int main() {
    // search in rotated sorted array [https://leetcode.com/problems/search-in-rotated-sorted-array/description/]

    vector<int> nums({4,5,6,7,0,1,2});
    int target = 0;

    int l = 0, r = nums.size()-1;

    int ans = -1;

    while (l <= r) {
        int mid = l+(r-l)/2;
        // verifica se segue os padroes de uma binary search:
        bool v = nums[r] > nums[mid];
        bool w = nums[l] <= nums[mid];
        // Se algum for falso, é preciso analisar o range e verificar se o valor está contido.

        if (nums[mid] == target) {ans = mid;}

        if (!v && (target > nums[mid] || target <= nums[r])) {
            l = mid+1;
        } else if (!w && (target >= nums[l] || target < nums[mid])) {
            r = mid-1;
        } else if (target > nums[mid]) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << "o index da ans é: " << ans;
}