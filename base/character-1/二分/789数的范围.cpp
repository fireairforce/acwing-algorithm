#include<iostream>
using namespace std;

int n;
const int N = 100000 + 7;
int q[N];

int main () {
  int n, k, query;
  cin >> n >> k;
  for (int i = 0;i<n;i++) {
    cin >> q[i];
  }
  // cout << "test" << endl;
  while (k --) {
    cin >> query;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      // 左边界
      if (q[mid] >= query) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (q[l] != query) {
      cout << "-1 -1" << endl; 
    } else {
      int start = l;
      l = 0, r = n -1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (q[mid] <= query) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      cout << start << " " << l << endl;
    }
  }
}