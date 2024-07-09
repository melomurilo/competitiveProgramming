#include <bits/stdc++.h>
using namespace std;

int mergeM(int a[], int l, int mid, int r) {
    int sz = r-l+1;
    int aux[sz], k = 0, c = 0;

    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
            c += (mid+1)-i;
        }
    }
    while (i <= mid) {
        aux[k++] = a[i++];
    }
    while (j <= r) {
        aux[k++] = a[j++];
    }

    for (int p = 0; p < sz; p++) {
        a[p+l] = aux[p];
    }
    return c;
}

int mergeSort(int a[], int l, int r) {
    if (l < r) {
        int c = 0;
        int mid = l+(r-l)/2;
        c += mergeSort(a, l, mid);
        c += mergeSort(a, mid+1, r);
        c += mergeM(a, l, mid, r);
        return c;
    }
    return 0;
}

int main() {
    // 5 = 4 inversoes
    // 4 = 3 inversoes
    // 7 inversoes;
    int arr[] = {5, 4, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = mergeSort(arr, 0, n-1);
    cout << x << '\n';
}