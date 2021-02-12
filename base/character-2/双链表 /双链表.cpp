#include<iostream>

using namespace std;

const int N = 100010;

int m;
int l[N], r[N], e[N], idx;

void init () {
  r[0] = 1, l[1] = 0;
  idx = 2;
}

// 在下标为 k 的点的右边插入 x
// 在左边插入的话，add(l[k], x)
void add (int k, int x) {
  e[idx] = x;
  r[idx] = r[k];
  l[idx] = k;
  l[r[k]] = idx;
  r[k] = idx;
  idx ++;
}


// 删除第 k 个点
void remove (int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main () {
  
  return 0;
}