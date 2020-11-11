#include<iostream>
using namespace std;
const int N = 1e5 + 7;
int q[N], temp[N];
typedef long long ll;

int merge_sort (int l ,int r) {
  if (l >= r) {
    return 0;
  }
  int mid = (l + r) >> 1;
  int res = merge_sort(l, mid) + merge_sort(mid + 1, r);
  int k = 0, i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) {
      temp[k++] = q[i++];
    } else {
      temp[k++] = q[j++];
      // 这里很巧妙 i 后面的到mid的数字都是小于j的就都可以加起来
      // 这里求的是数字在左侧和右侧逆序对的情况
      res += (mid - i + 1);
    }
  }
  while (i <= mid) {
    temp[k++] = q[i++];
  }
  while (j <= r) {
    temp[k++] = q[j++];
  }
  for (i = l, j = 0;i <= r; i++, j++) {
    q[i] = temp[j];
  }
  return res;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0;i<n;i++) {
        cin >> q[i];
    }
    cout << merge_sort(0, n - 1) << endl;
    return 0;
}