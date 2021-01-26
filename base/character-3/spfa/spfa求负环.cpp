#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int e[N], w[N], h[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];
int n, m;

void add (int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool spfa () {
  queue<int>q;
  // 把所有点全部放进去队列里面,因为找负环可能从1出发找不到
  for (int i = 1; i <= n; i++) {
    st[i] = true;
    q.push(i);
  }

  while(q.size()) {
    int t = q.front();
    q.pop();
    st[t] = false;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
        dist[j] = dist[t] + w[i];
        // 记录一下到 j 这个点的边数
        cnt[j] = cnt[t] + 1;
        if(cnt[j] >= n) {
          return true;
        }
        if (!st[j]) {
          q.push(j);
          st[j] = true;
        }
      }
    }
  }
  return false;
}

int main () {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while (m--) {
    int a,b,c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  bool t = spfa();
  if (t) {
      cout << "Yes" << endl;
  } else {
      cout << "No" << endl;
  }
  return 0;
}