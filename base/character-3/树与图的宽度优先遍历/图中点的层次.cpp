#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m;
// 构建领接表
int e[M], ne[M], h[N], idx;

int ans = N;
// d 是距离, q 是队列
int d[N], q[N];

void add (int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int bfs () {
  int tt = 0, hh = 0;
  q[0] = 1;
  memset(d, -1, sizeof d);
  d[1] = 0;
  while(hh <= tt) {
    int t = q[hh++];
    // 直接拓展一下每个点的领边
    for (int i = h[t] ; i!= -1;i=ne[i]) {
      int j = e[i];
      // 如果这个点没有访问过
      if (d[j] == -1) {
        d[j] = d[t] + 1;
        q[++tt] = j;
      }
    }
  }
  return d[n];
}

int main () {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for (int i = 1;i<=m;i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
  }

  cout << bfs() << endl;
  return 0;
}