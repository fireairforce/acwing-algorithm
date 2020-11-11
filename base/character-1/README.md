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
    // 注意这里一定要取出来值，如果取下标会wa
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
      tmp[k++] = q[i++];
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

## 整数二分

二分查找的算法模版可以参考 y 总的[文章](https://www.acwing.com/blog/content/31/)

```cpp
// 区间[l, r]被划分为[l, mid]和[mid + 1, r] 时使用:
int bsearch_1 (int l, int r) {
  while (l < r) {
    int mid = (l + r) >> 1;
    if (checked(mid)) r = mid; // check 用来判断 mid 是否满足性质
    else l = mid + 1;
  }
  return l;
}

// 区间[l, r] 被划分为 [l, mid - 1] [mid, r] 时使用:
int bsearch_2 (int l, int r) {
  while (l < r) {
    // cpp 里面的除法是向下取整的，否则当 l = r - 1 的时候，会死循环(如果check成功l会一直等于l)
    int mid = (l + r + 1) >> 1;
    // 如果check成功结果是 l = mid ,那么我们就需要给 mid 补个1
    if (check(mid)) l = mid;
    else r = mid -1;
  }
  return l;
}
```

二分的本质其实并不是单调性，二分的本质实际上是边界问题，其实是某个性质在某个区间可以满足，在另外一个区间里面不能满足(这个性质可以将一个区间一分为二，从而我们利用二分去寻找这两个区间的边界)。

一般我们要解决的问题有以下两种情况:
二分一共有两种情况，如果我们要二分出来的边界点在左边区间的右边
1. 找一个中间值(`(l + r + 1) >> 1`)，判断这个中间值是否满足这个性质,如果满足，那么我们要找的边界点就在 `[mid, r]` 这个区间里面,我们更新 l = mid 即可，如果不满足的话，那么要找的边界点就在 `[l, mid - 1]` 这个区间里面，更新 `r = mid - 1` 即可。使用第二组模版。

如果二分出来的边界点在右边区间的左边
2. 中间值 `mid = (l + r) >> 1`, 如果 `mid `这个点的值满足性质的话，那么就在 `[l, mid]` 这个区间里面，此时 `r = mid`,如果不满足，就在 `[mid + 1, r]` 这边，那么更新 `l = mid + 1`。使用第一组模版。

一般二分问题我们先写一个 check 函数，然后思考如果根据 check 的结果去更新我们的区间。


## 浮点数二分
相比较于整数二分，浮点数二分没有那么多边界条件需要处理。

以求平方根为例子:
```cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main () {
  double x;
  cin >> x;
  double l = 0, r = max(1, x);
  // 根据精度就可以判定是否结束循环了
  while (r - l > 1e-8) {
    double mid = (l + r) / 2;
    if (mid * mid >= x) {
       r = mid;
    } else {
      l = mid;
    }
  }
  cout << l << endl;
  return 0;
}
```

浮点数二分也可以直接改成迭代的写法(直接迭代100次):
```cpp
for (int i = 0;i<100;i++) {
  double mid = (l + r) >> 1;
  if (mid * mid >= x) {
    r = mid;
  } else {
    l = mid;
  }
}
```