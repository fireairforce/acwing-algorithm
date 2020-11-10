#include<iostream>
using namespace std;

bool checked (int x) {
  return !!x;
}

int bsearch_1 (int l , int r) {
  while (l < r) {
  int mid = (l + r) >> 1;
    if (checked(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int bsearch_2 (int l, int r) {
  while (l < r) {
    int mid = (l + r + 1) >> 1;
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