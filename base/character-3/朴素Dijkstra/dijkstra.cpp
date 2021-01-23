#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 510;

int n, m;
// 领接矩阵，存图
int g[N][N];
// 记录起始点到其他点的最短距离
int dist[N];
// st存知道最短路的点
bool st[N];

int dijkstra () {
  // 其他点为正无穷
  memset(dist, 0x3f, sizeof dist);
  // 把起始点的距离初始化为 0
  dist[1] = 0;

  // 每一次循环都可以得到一个点到起点到最短距离
  for (int i = 0; i < n; i++) {
    int t = -1;
    for (int j = 1; j <= n; j++) {
      // 从 st[j] 为 false 的点中找到 dist 最短点
      if (!st[i] && (t == -1 || dist[t] > dist[j])) {
        t = j;
      }
    }
    // 找到最短路就退出出去
    if (t == n) break;
    st[t] = true;
    
    // 这里其实就是利用 t 来去更新其他点到起点的距离
    for (int j = 1; j <= n; j++) {
      dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
  }
  if (dist[n] == 0x3f3f3f3f) return -1;

  return dist[n];
}

int main () {
  cin >> n >> m;
  // 初始化其他点为正无穷
  // 0x3f 转换成二进制放到 g 里面会是一个很大的数字
  memset(g, 0x3f, sizeof g);
  while (m --) {
    int a, b, c;
    cin >> a >> b >> c;
    // 重边判断一下
    g[a][b] = min(g[a][b], c);
  }

  int t = dijkstra();
  if (t == 0x3f3f3f3f) {
    cout << -1 << endl;
  } else {
    cout << t << endl;
  }
  return 0;
}