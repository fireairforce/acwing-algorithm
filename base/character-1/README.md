## 快排
- 确定分界点(可以随意选择一个值)
- 调整区间(第一个区间里面的值都小于等于x，第二个区间则大于x)
- 递归处理两个区间

难以处理的部分在第二段里面。

可以开两根指针往中间走，分别为i和j，i从左边往中间走，如果值比x小，i可以继续移动，否则i停下来，j从右边往中间走，同理i，如果 `i<j` 就交换他们的位置上的值，直到 i 和 j 相遇为止。

这部分要处理一些边界问题，要记得把模版背下来。

```cpp
#include <iostream>
using namespace std;
int n;
const int N = 1e5 + 7;
int q[N];
void quick_sort(int a[], int l , int r) {
    if (l >= r) return;
    // 先取到中枢的值
    int x = a[(l + r ) >> 1], i = l - 1, j = r + 1;
    // 然后用两根指针去扫
    while (i < j) {
      // i往左边扫，遇到大于x的值停下来
        while (a[++i] < x);
        // j往右边扫，遇到小于x停下来
        while (a[--j] > x);
        // 扫完之后把 i 和 j换位置
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    // 去递归处理左边区间和右边区间
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
```

## 归并排序

其思想为分治

- 确定分界点(mid = (l + r) >> 1)
- 递归排序左边和右边
- 归并，把两个有序的数组合并为一个(双指针)

思想为双指针算法

模版为:
```cpp
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000010;

int n;
int q[N], tmp[N];

void merge_sort (int q[], int l, int r) {
  
  if (l >= r) {
    return;
  }
  // 确定中点
  int mid = (l + r) >> 1;
  // 递归排序左边和右边
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);
  // i j 为双指针左右两边边界的起点
  int k = 0, i = l, j = mid + 1;
  // 然后开始归并，把两个有序序列归并成一个放到一个tmp数组里面去
  while (i <= mid && j <= r) {
    if (q[i] < q[j]) {
      tmp[k++] = q[i ++];
    } else {
      tmp[k++] = q[j++];
    }
  }
  // 上面如果没有比较完的情况
  while (i <= mid) {
    tmp[k++] = q[i++];
  }
  while (j <= r) {
    tmp[k++] = q[j++];
  }
  // 结果复制回去
  for (i = l, j = 0; i<=r; i++, j++) {
    q[i] = tmp[j];
  }
}

int main () {
  scanf("%d", &n);
  for (int i = 0;i < n; i++) {
    scanf("%d", &q[i]);
  }
  merge_sort(q, 0, n - 1);
  for (int i = 0;i<n;i++) printf("%d ", q[i]);
  return 0;
}
```