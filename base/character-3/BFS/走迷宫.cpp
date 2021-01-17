#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int n,m;
int d[N][N];
int g[N][N];

// prev 记录前面一个点是从哪里过来的
PII q[N * N], Prev[N][N];


int bfs () {
  int hh = 0, tt = 0;

// 因为这里有波初始化，所以 hh 初始值是 -1
  q[0] = make_pair(0, 0);

  memset(d, -1, sizeof(d));
  d[0][0] = 0;

  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// 维护两根指针去表示队列，其中 hh 为队列头, tt 为队列尾部
  while (hh <= tt)
  {
    auto t = q[hh++];

    for (int i = 0;i < 4;i++) {
      int x = t.first + dx[i], y = t.second + dy[i];
      if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1){
        d[x][y] = d[t.first][t.second] + 1;
        Prev[x][y] = t;
        q[++tt] = make_pair(x, y);
      }
    }
  }
  int x = n - 1, y = m - 1;
  // 沿着终点往回推就可以得出 bfs 搜索过来的路径了
  while (x || y) {
    cout << x << ' ' << y << endl;
    auto t = Prev[x][y];
    x = t.first, y = t.second;
  }
  return d[n-1][m-1];
}

int main () {
   cin >> n >> m;
   for (int i = 0;i<n;i++) {
     for (int j = 0;j<m;j++) {
       cin >> g[i][j];
     }
   }
   cout << bfs() << endl;
  return 0;
}