#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
const int M = 1e5 + 10;
int n, m;
// 因为是稠密图，所以存的时候用领接矩阵存
int g[N][N];
int dist[N];
bool st[N];

int prim() {
  memset(dist, 0x3f, sizeof dist);

  int res = 0;
  for (int i = 0; i< n; i++) {
    int t = -1;
    for (int j = 1;j<=n;j++) {
      if (!st[j] && (t==-1 || dist[t] > dist[j])) {
        t = j;
      }
    }
    if (i && dist[t] == INF) return INF;
    if (i) res += dist[t];
    // 这里的 dist 表示点到集合里面点的最短距离
    for (int j = 1; j<=n;j++) dist[j] = min(dist[j], g[t][j]);
    st[t] = true;
  }
  return res;
}

int main () {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  while (m --)
  {
    int a, b, c;
    cin >> a >> b >> c;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  int t = prim();

  if (t==INF) {
    puts("impossible");
  } else {
    cout << t << endl;
  }
  
  return 0;
}