#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
// d 表示存 入度的数组
int q[N], d[N];

// 这一步是构建图的操作，没看太明白
void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort() {
  int hh = 0, tt = -1;

  for (int i = 1; i <= n;i ++) {
    if (!d[i]) {
      // 这里是用数组来模拟
      q[++ tt] = i;
    }
  }
  while (hh <= tt) {
    int t = q[hh ++];
    for (int i = h[t]; i != -1; i=ne[i]) {
      // j 表示 i -> 指向的那个点
      int j = e[i];
      d[j] --;
      if (!d[j]) q[++tt] = j;
    }
  }
  // 如果队列里面存的值
  return tt == n - 1;
}

int main () {
  cin >> n >> m;

  memset(h, -1, sizeof(h));

// 一共有 m 条边
  for (int i = 0;i < m;i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    // 有一条a 指向 b 的边，那么b 的入度就可以 ++
    d[b] ++;
  }
  // 判断是否存在拓扑序列
  if (topsort()) {
   for (int i = 0;i < n; i++) cout << q[i] << " ";
  } else {
    cout << -1 << endl;
  }
  return 0;
}