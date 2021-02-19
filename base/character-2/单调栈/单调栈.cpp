#include<iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;
// 输出每个数左边比它小的数
// 在每次遍历过程中，用栈来存一个新的元素，然后找值的时候，每次从栈顶开始找
// 在这个过程中会发现，

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n ;i ++) {
    int x;
    cin >> x;
    while (tt && stk[tt] >= x) tt--;
    if (tt) cout << stk[tt] << " ";
    else cout << -1 << " ";
    stk[++tt] = x; 
  }
  return 0;
}