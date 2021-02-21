#include<iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
char p[N], s[M];
int ne[N];

int main () {
  cin >> n >> (p + 1) >> m >> (s + 1);

  // 求 next 数组过程
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[i] != p[j + 1]) {
      j = ne[j];
    }
    if (p[i] == p[j + 1]) {
      j ++;
    }
    ne[i] = j;
  }

  // kmp 匹配过程
  // i 枚举的是当前的 s[i]
  for (int i = 1, j = 0; i <= m; i ++) {
    // j 则找的是 p[j + 1] 和 i 错开一位
    while (j && s[i] != p[j + 1]) {
      // 匹配不了就往后面退
      j = ne[j];
    }
    // 匹配了就 j 往后走 
    if (s[i] == p[j + 1]) {
      j ++;
    }
    if (j == n) {
      // 匹配成功
      cout << i - n << " ";
      // j 再往后面走
      j = ne[j];
    }
  }
  return 0;
}