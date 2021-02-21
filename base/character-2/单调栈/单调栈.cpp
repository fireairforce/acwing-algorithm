#include<iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;
// 输出每个数左边比它小的数
// 在每次遍历过程中，用栈来存一个新的元素，然后找值的时候，每次从栈顶开始找
// 在这个过程中会发现，(a1,a2 指栈中元素)会发现 ax >= ay (x < y) 存在有这样一种逆序的关系那么结果肯定会是 ay
// 这样栈可以被我们维持成一个单调的序列
// 每次我们从栈顶找到小于当前 x 值的值(这个过程中会把其他的栈顶的值弹出去)

// 单调栈因为整个数组里面的元素都只会进栈一次，实际上的时间复杂度是 O(2N)
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n ;i ++) {
    int x;
    cin >> x;
    // 这里是个找值的过程 && 在这个过程中会清一下栈顶的元素
    while (tt && stk[tt] >= x) tt--;
    // 如果栈里面找到值了
    if (tt) cout << stk[tt] << " ";
    // 栈空了就没值了
    else cout << -1 << " ";
    // 每一轮找完之后就把当前这个值放在栈顶就行
    stk[++tt] = x; 
  }
  return 0;
}