#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, q;

int d[N][N];

void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= n; i++) {
        d[j][i] = min(d[j][i], d[j][k] + d[k][i]);
      }
    }
  }
}

int main () {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = INF;
      }
    }
  }
  while (m --) {
    int a, b, w;
    cin >> a >> b >> w;
    d[a][b] = min(d[a][b], w);
  }
  floyd();
  while (q --) {
    int a, b;
    cin >> a >> b;
    cout << d[a][b] << endl;
  }
  return 0;
}