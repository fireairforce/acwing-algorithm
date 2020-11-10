#include<iostream>
using namespace std;

int bsearch_1 (int l , int r) {
  int mid = (l + r) >> 1;
  while (l < r) {
    if (checked(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int bsearch_2 (int l, int r) {
  int mid = (l + r + 1) >> 1;
  while (l < r) {
    if (checked(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main () {
  return 0;
}