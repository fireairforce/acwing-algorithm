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

pair<int, int> q[N * N];


int bfs () {
  int hh = 0, tt = 0;

  q[0].first = q[0].second = 0;

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
        tt ++;
        q[tt].first = x;
        q[tt].second = y;
      }
    }
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