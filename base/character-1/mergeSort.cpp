#include<iostream>
using namespace std;

const int N = 1e6 + 7;
int a[N], temp[N];

void merge_sort(int q[], int l, int r) {
  if (l >= r) {
    return;
  }
  int mid = (l + r) >> 1;
  // 递归去排序左边和右边数组
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);

  // 归并的过程，把有序数组放入temp里面去
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) temp[k++] = q[i++];
    else temp[k++] = q[j++];
  }
  while (i <= mid) {
    temp[k++] = q[i++];
  }
  while (j <= r) {
    temp[k++] = q[j++];
  }
  // 把值复制回原来的数组
  for (i = l, j = 0;i <= r; i++, j++) {
    q[i] = temp[j];
  }
}

int main () {
  int n;
  cin >> n;
  for (int i = 0;i<n;i++) {
    cin >> a[i];
  }
  merge_sort(a, 0,n -1);
  for (int i = 0;i<n;i++) {
    cout << a[i] << " ";
  }
  return 0;
}
