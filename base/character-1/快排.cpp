#include <iostream>
using namespace std;
int n;
const int N = 1e5 + 7;
int q[N];
void quick_sort(int a[], int l , int r) {
    if (l >= r) return;
    int x = a[(l + r ) >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}
int main () {
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0;i<n;i++) {
        cout << q[i] << " "; 
    }
}