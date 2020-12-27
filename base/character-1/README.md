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

## 高精度加法

模拟正常情况下的加法就行了

```cpp
vector<int> add(vector<int> &a, vector<int> &b) {
  if(a.size() < b.size()) {
    return add(b, a);
  }
  int k = 0;
  vector<int>C;
  for (int i = 0;i<a.size();i++) {
    k += a[i];
    if (i < b.size()) {
      k += b[i];
    }
    C.push_back(k % 10);
    k /= 10;
  }
  if (k) {
    C.push_back(1);
  }
}
```

## 高精度减法

模版保证 `A >= B`.
高精度减法分每一位的大小比较，来判断是否需要借位的操作。


## 高精度乘法
保证 A * b (b 是个有限制的整型，在每次乘的时候，把b看作一个整体)。

## 前缀和

要保证数组的下标从 1 开始，为了便于计算。

```cpp
for (int i = 1;i<=n;i++) {
  s[i] = s[i - 1] + a[i- 1];
}
```

作用： 能够快速求出原数组里面的某一段的和(例如求数组[l, r] 这段区间里面的值，可以使用`s[r] - s[l - 1]` 来计算出值)。

二维情况见目录下代码。

## 差分

差分本质上为前缀和的逆运算。

假设原数组是 a1 a2 ...an 假设要构造b数组，使得 ai = b1 + b2 + .. bi(即a数组是b数组的前缀和)

那么构造的方式可以为 
b1 = a1 b2 = a2 - a1 ...

那么此时b数组就是a数组的差分.

差分数组能让很多操作里面，在a数组里面[l, r]这段区间里面加一个常数(把时间复杂度从O(N)降到O(1)，那么对于b数组(即差分数组)，我们只需要给bl+c,那么a数组里面[l, a.length - 1]这段区间里面的值都会加上一个c，然后我们要求[l,r]这段区间加c后的值，则需要在[r+1]这一段执行一个减去c的操作)。

差分不用考虑怎么去构造，二维的差分则是相当于给子矩阵里面的某块区域加上某个值。

## 双指针

所有双指针算法的时间复杂度都是O(N)。

双指针算法最核心的作用就是将某些朴素的枚举算法(o(N^2))优化到o(N).

模版大概就是:
```cpp
for (int i = 0,j = 0; i < n; i++) {
  while (j < i && check(i, j)) {
    j++;
  }
  // 每道题目的具体逻辑
}
```

## 常用的位运算操作

### 求一个整数n的二进制表示的第k位数字是几

例如: n = 15 = (1111)2

个位当作第 0 位.

1. 先把第 k 位数字移到最后一位 n >> k
2. 看下个位是多少，例如个位是x,x & 1 就可以知道个位是多少了

```cpp
n >> k & 1;
```

如上式子即可。

### lowbit
lowbit 是树状数组的一个基本操作，lowbit 的作用是返回数字 x 最后一个 1 的位置.

```cpp
x = 1010 lowbit(x) = 10
x = 101000 lowbit(x) = 1000
```

操作方法就是: 
```cpp
lowbit(x) = x & -x
// 因为在 cpp 中
-x = ~x + 1;
// so 
x & -x = x & (~x + 1);
// 具体的操作可以自己手画图来表示一下。
```

借助于 lowbit 可以统计一下 x 二进制里面1的个数
每次循环的时候，都减去这个数的 lowbit 值，能求出 x 里面 1 的个数

```cpp
#include<iostream>

using namespace std;

int lowbit (int x) {
    return x & -x;
}

int main () {
    int n;
    cin >> n;
    while (n --) {
        int x;
        cin >> x;
        int res = 0;
        while (x) {
            // 每次减去 x 里面的1
            x -= lowbit(x);
            res ++;
        }
        cout << res << " ";
        
    }
    return 0;
}
```

## 离散化

离散化这里特指整数的离散化。

特征是值域跨度很大，但是值比较稀疏

把一些范围很大，但是值很少的一些数值映射一下，如下表示

```bash
// 注意a数组要求是有序的
a[i]  1 3 1000 2000 500000
     0  1  2     3    4
```
- a[] 中可能有重复元素(去重)
- 如何算出 a[i] 离散化之后的值(二分)

去重可以采用 cpp 里面的一些库函数
cpp 里面使用 vector 来做离散化.

```cpp
vector<int> alls;  // 存储所有待离散化的值
sort(alls.begin(), alls.end());  // 将所有数值排序
alls.earse(unique(alls.begin(), alls.end()), alls.end()); // 去掉重复元素

// 二分求出 x 对应的离散化的值

int find (int x) { // 找到第一个大于等于 x的位置，然后返回+1的值
  int l = 0 , r = alls.size() - 1;
  while (l < r) {
    int mid = l + r >> 1;
    if (alls[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return r + 1; // +1 的话就从 1 开始映射，1...alls.length, 否则从0开始
}
```
可以参考区间和这道题目。

759 这题也可以去看一下。

## 区间合并

把有交集的区间合并，然后生成一个新的区间。

这种问题可以当作一种模型题目来求解。

- 按照区间的左端点排序
- 扫描整个区间 && 扫描过程中对区间进行合并

