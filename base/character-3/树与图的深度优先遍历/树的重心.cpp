#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010, M = N * 2;

// h[N]是初始化
int h[N], e[M], ne[M], idx;

// 存遍历的点
bool st[N];

int ans = N;
int n;

// 领接表插入从 a -> b 的一条边
// 基本上所有树和图的问题都是这么存的
void add (int a, int b) {
  e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
}

// dfs 返回的是 以 u 为根的子树中点的数量
int dfs(int u) {
  // 标记
  st[u] = true;
  
  int sum = 1, res = 0;
  for (int i = h[u]; i != -1;i=ne[i]) {
    int j = e[i];
    if (!st[j]) {
      // j 没有走过就去搜这个点
      int s = dfs(j);
      res = max(res, s);
      sum += s;
    }
  }

  // 子树上面的一部分
  res = max(res, n - sum);

  ans = min(ans, res);

  return sum;
}


int main () {
  // 把 h 里面的值初始化成 -1
  cin >> n;
  // memset 是按照字节去进行赋值的，可以对数组进行 -1 和 0 的初始化赋值
  memset(h, -1, sizeof h);
  
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    // 因为是无向图，所以这里需要存 a -> b 也要存 b -> a
    add(a, b), add(b ,a);
  }

  dfs(1);

  cout << ans << endl;

  return 0;
}