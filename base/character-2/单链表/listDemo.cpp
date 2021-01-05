#include<iostream>

using namespace std;

const int N = 100010;

// head 表示头节点的下标
// e[i] 表示节点 i 的值
// ne[i] 表示节点 i 的 next 指针的值
// idx 存当前可以使用的最新的节点的下标
int head, e[N], ne[N], idx;

// 初始化操作
void init () {
  head = -1;
  idx = 0;
}

// 把 x 插入头节点
// 分两步来完成 让 x 节点的 next 指针指过去 head 存的值
// 第二步让 head 指向新增的节点(更新一下idx)
void add_to_head(int x) {
  e[idx] = x;
  ne[idx] = head;
  head = idx;
  idx ++;
}

// 将 x 这个点插入到下标 k 的结点的后面
void add(int x, int k) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  idx ++;
}

// 删除下标为k的点后面的点删掉
void remove(int k) {
  // 直接跳到它后面点的next上面去
  ne[k] = ne[ne[k]];
}

int main () {
  return 0;
}