#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 1e5 + 7;
int a[N], b[N];

int main () {
  int n, m;
  cin >> n >> m;
  for (int i = 0;i<n;i++) {
    cin >> a[i];
  }

  for (int i = 0;i<m;i++) {
    cin >> b[i];
  }

  int count = 0;
  for (int i = 0, j = 0;i<n;i++) {
    while (a[i] != b[j] && j < m - 1) {
      j ++;
    }
    if (a[i] == b[j] && j < m) {
      j ++;
      count ++;
    }
  }
  if (count == n) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}