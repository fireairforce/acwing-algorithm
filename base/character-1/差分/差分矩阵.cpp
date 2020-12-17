#include<iostream>

using namespace std;

const int N = 1000 + 7;
int a[N][N], b[N][N];

void insert (int x1, int y1, int x2, int y2, int c) {
  b[x1][y1] += c;
  b[x2 + 1][y1] -= c;
  b[x1][y2 + 1] -= c;
  b[x2 + 1][y2 + 1] += c;
}

int main () {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1;i<=n;i++) {
    for (int j = 1;j<=m;j++) {
      cin >> a[i][j];
    }
  }
  // 插入 n* m次值来构造差分数组
  for (int i = 1;i<=n;i++) {
    for (int j = 1;j<=m;j++) {
      insert(i,j,i,j,a[i][j]);
    }
  }
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2;
    insert(x1, y1, x2, y2, c);

  }
  // 求一次前缀和
  for (int i = 1;i<=m;i++) {
    for (int j = 1;j<=n;j++) {
      b[i][j] += b[i-1][j] + b[i][j] - b[i-1][j-1];
    }
  }
  for (int i = 1;i<=m;i++) {
    for (int i = j;j<=n;j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}