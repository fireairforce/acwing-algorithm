#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

// 堆优化的 dijkstra 一般针对稀疏图
const int N = 1e5 + 10, M = 2 * N;
// 这里的 w 是用来存权重的
int h[N], e[M], ne[M], w[M], idx = 0;
int n, m;
int dist[N];
bool st[N];

// 使用堆来维护节点到起点的距离
typedef pair<int, int> PII;


void add (int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra () {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  // 使用优先队列维护, 小根堆，不指定 greater 参数就默认是大顶堆
  // vector 表示优先队列使用什么来实现，一般使用 vector 比较合适
  priority_queue<PII, vector<PII>, greater<PII> > heap;
  // 1号点距离为0
  heap.push(make_pair(0, 1));
  // 有点像 bfs 的感觉
  while (heap.size()) {
    auto t = heap.top();
    heap.pop();

    // distance 是(点t)距离，ver 是点
    int ver = t.second, distance = t.first;
    // 如果这个点已经被计算过了，就直接跳了
    if (st[ver]) continue;
    // 这里记得加上这个判断
    st[ver] = true;
    // 这里的时间复杂度只有 m
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > distance + w[i]) {
        dist[j] = distance + w[i];
        heap.push(make_pair(dist[j], j));
      }
    }
  }
  if (dist[n] == 0x3f3f3f3f) {
    return -1;
  }
  return dist[n];
}

int main () {
  cin >> n >> m;
  memset(h, -1, sizeof h);

  while (m --) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  int t = dijkstra();
  cout << t << endl;
  return 0;
}