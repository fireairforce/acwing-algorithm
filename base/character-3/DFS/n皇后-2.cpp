// 按照格子去进行一个枚举
#include<iostream>
#include<cstdio>
using namespace std;
// 注意这个 N 值不要开太小了，因为下面 bool 数组会使用
const int N = 20;

char g[N][N];

bool col[N], dg[N], udg[N], row[N];

int n;

void dfs(int x, int y, int s) {
  if (y == n) {
    y = 0;
    x ++;
  }
  if (x == n) {
    if (s == n) {
      for (int i = 0;i<n;i++) {
        puts(g[i]);
      }
      puts("");
    }
  }

  // 不放皇后
  dfs(x, y + 1, s);

  if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) {
    g[x][y] = 'Q';
    row[x] = col[y] = dg[x + y] = udg[x-y+n] = true;
    dfs(x, y + 1, s + 1);
    row[x] = col[y] = dg[x + y] = udg[x-y+n] = false;
  }
}

int main () {
    cin >> n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            g[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}