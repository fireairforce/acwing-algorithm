#include<iostream>

using namespace std;
const int N  = 10;

int n;
// 用来记录被用过的点
bool st[N];
// 记录排列的节点
int path[N];

void dfs (int u) {
  // 边界情况
  if (u == n){
    for (int i = 0;i<n;i++) {
      cout << path[i] << " ";
    }
    cout << endl;
    return;
  }

  // u < n 的时候，枚举一下当前可以填哪些数字
  for (int i = 1; i <= n; i++) {
    // 然后找一个没有使用过的数字
    if (!st[i]) {
      path[u] = i;
      st[i] = true;
      dfs(u + 1);
      // 从递归里面出来的时候恢复
      st[i] = false;
    }
  }
}

int main () {
  cin >> n;
  dfs(0);
  return 0;
}