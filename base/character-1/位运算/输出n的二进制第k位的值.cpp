#include<iostream>
#include<cstring>

using namespace std;

int main () {
  int n = 10;
  // 这里实际输出的是 n 的二进制表示
  for (int k = 3; k>=0;k--) {
    cout << (n >> k & 1);
  }
  return 0;
}