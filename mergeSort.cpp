#include <bits/stdc++.h>
using namespace std;

void merge1(int b[], int l, int mid, int r) {
    int sz = (r-l)+1;
    int aux[sz];
    int k = 0;
    
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (b[i] < b[j]) {
            aux[k++] = b[i++];
        } else {
            aux[k++] = b[j++];

        }
    }

    while(i <= mid) {
        aux[k++] = b[i++];

    }
    while(j <= r) {
        aux[k++] = b[j++];

    }
    for (int p = 0; p < sz; p++) {
        b[p+l] = aux[p];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge1(arr, l, mid, r);
    }
}

int main() {
    int n[] = {3, 7, 8, 5, 4, 2, 6, 1};
    int sz = sizeof(n)/sizeof(n[0]);
    mergeSort(n, 0, sz-1);
    for (int u : n) {
        cout << u << ' ';
    }
}