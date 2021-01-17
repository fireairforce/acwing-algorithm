#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

typedef pair<int, int> PII;

const int N = 9;
char g[N][N];
int ans = 0;
// https://stackoverflow.com/questions/15016646/using-pairint-int-as-key-for-map
// map 以 pair 为key 构建 hash 表
map<PII, char> has1;
map<char, PII> has2;

void init () {
  char str = '1';
  for (int i = 1;i<=3;i++) {
    for (int j = 1;j<=3;j++) {
      if (i ==3 && j == 3) {
        has1[make_pair(i, j)] = 'x';
        has2['x'] = make_pair(i, j);
      } else {
        has1[make_pair(i, j)] = str;
        has2[str] = make_pair(i, j);
        str ++;
      }
    }
  }
}

int bfs () {
  // 队列头指针和尾部指针
  PII q[N * N];
  int hh = 0, tt = 0;
  
}


int main () {
  for (int i = 1;i<=3;i++) {
    for (int j = 1;j<=3;j++) {
      cin >> g[i][j];
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (g[i][j] != has1[make_pair(i, j)]) {
      }
    }
  }
  return 0;
}