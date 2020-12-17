#include<iostream>

using namespace std;
int a[100000] = {0}, b[100007] = {0};

void insert (int l, int r, int c) {
  b[r] += c;
  b[l + 1] -=c;
}

int main () {
  int n, m;
  cin >> n >> m;
  for (int i = 1;i<=n;i++) {
    cin >> a[i];
  }
  for (int i = 1;i<=n;i++) {
    insert(i,i,a[i]);
  }
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    insert(l, r, x);
  }
  // 对数组本身求个前缀和(b为差分数组)
  for (int i = 1;i<=n;i++) {
    b[i] += b[i-1];
  }
  for (int i =1;i <= n;i++) {
    cout << b[i] << endl;
  }
  return 0;
}