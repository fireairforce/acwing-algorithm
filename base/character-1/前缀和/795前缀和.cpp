#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[100007] = {0};
int s[100008] = {0};

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 0;i<n;i++) {
    cin >> a[i];
  }
  for (int i = 1;i<=n;i++) {
    s[i] = s[i - 1] + a[i- 1];
  }
  int l, r;
  for (int i = 0;i < m; i++) {
    cin >> l >> r;
    cout << s[r] - s[l - 1] << endl;
  }
  return 0;
}