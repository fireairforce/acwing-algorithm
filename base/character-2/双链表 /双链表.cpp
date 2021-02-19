#include<iostream>

using namespace std;

const int N = 100010;

int m;
// e 表示点点值，l 表示左边点是谁，r 表示右边点
int l[N], r[N], e[N], idx;

void init () {
  // 0 表示左端点，1 表示右端点，然后让他们互相指向
  r[0] = 1, l[1] = 0;
  // idx 则从2开始，因为 0, 1 已经被占用了
  idx = 2;
}

// 在下标为 k 的点的右边插入 x
// 在左边插入的话，add(l[k], x)
// 这里一共要改四条边的操作
void add (int k, int x) {
  // 赋值
  e[idx] = x;
  // 确定右边指针
  r[idx] = r[k];
  // 左边指针则为 k
  l[idx] = k;
  // 插入点的左边指向 idx 
  l[r[k]] = idx;
  // r[k] 也要修改，注意和上一步的先后顺序
  r[k] = idx;
  idx ++;
}


// 删除第 k 个点
// 这里就只有两个指针的操作
// 直接让这个点的左边的右边直接等于我的右边，右边的左边直接等于我的左边
void remove (int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main () {
  return 0;
}