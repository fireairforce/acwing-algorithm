#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

// 这题限制了经过的边的个数(存在负权回路其实也无所谓了)
using namespace std;
const int N = 510, M = 100010;

int n, m, k;
int dist[N], backup[N];

struct Edge {
  int a;
  int b;
  int w;
} edges[M];

int bellman_ford () {
  memset(dist, 0x3f, sizeof dist);
  // 不超过 k 次，就迭代 k 次就行了
  dist[1] = 0;
  for (int i = 0; i < k; i ++) {
    // 这题要用 backup 数组来进行一次备份
    // 不加备份的话，可能会导致枚举边的时候发生串联操作,每次迭代只用上一次的结果
    memcpy(backup, dist, sizeof dist);
    for (int j = 0; j < m; j ++) {
      int a = edges[j].a, b = edges[j].b, w = edges[j].w;
      // 这里只用上一次的结果来进行一次更新，防止其他的点被提前更新了
      dist[b] = min(dist[b], backup[a] + w);
    }
  }
  // 这里不能用 == 0x3f3f3f 因为存在负权边时， 0x3f3f3f3f + (负值)，最后被更新出的值就会小于无穷
  if (dist[n] > 0x3f3f3f3f / 2) {
    return -1;
  } else {
    return dist[n];
  }
}

int main () {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[i].a = a;
    edges[i].b = b;
    edges[i].w = w;
  }
  int t = bellman_ford();

  if (t == -1) {
    puts("impossible");
  } else {
    cout << t << endl;
  }
  return 0;
}