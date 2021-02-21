#include<iostream>

using namespace std;

const int N = 1000010;

int a[N], q[N];
int n, k;

// 这里队列里面存的不是值，而是下标
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++ ){
    cin >> a[i];
  }
  int hh = 0, tt = -1;
  // 求出滑动窗口的最小值
  for (int i = 0; i < n; i++) {
    // 判断队头是否已经滑出了窗口(因为队头始终是个最小的值)
    // 每次窗口只会滑动一次，因此这只用判断一次
    if (hh <= tt && i - k + 1 > q[hh]) hh++;
    // 从队尾开始判断，如果队尾有值比当前值还要大，那么可以直接弹出去了
    while (hh <= tt && a[q[tt]] >= a[i]) tt --;
    // 每次操作完成之后都要把当前值的下标加进去
    q[++ tt] = i;
    // 只有在 i 满足滑动窗口范围之后开始打印值
    if (i >= k - 1) cout << a[q[hh]] << " ";
  }
  cout << endl;
  // 找最大值的话，同样更新一下判断就行
  hh = 0, tt = -1;
  for (int i = 0; i < n; i++) {
    // 队头是否滑出去了
    if (hh <= tt && i - k + 1 > q[hh]) hh++;
    while (hh <= tt && a[q[tt]] <= a[i]) tt --;
    q[++ tt] = i;
    if (i >= k - 1) cout << a[q[hh]] << " ";
  }
  cout << endl;
  return 0;
}