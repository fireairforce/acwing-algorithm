#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e5 + 7;
int arr[N];

void quick_sort(int l, int r, int k) {
    if (l >= r) {
        cout << arr[l] << endl;
        return;
    }
    int item = arr[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        while (arr[++i] < item);
        while (arr[--j] > item);
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    int num = j - l + 1;
    if (num >= k) {
        quick_sort(l, j, k);
    } else {
        // 这里记得去右边找的值要减去左边区间的数目
        quick_sort(j + 1, r, k - num);
    }
}

int main () {
  int n, k;
  scanf("%d %d",&n, &k);
  for (int i = 0;i<n;i++) {
    scanf("%d", &arr[i]);
  }
  quick_sort(0, n-1, k);
  return 0;
}