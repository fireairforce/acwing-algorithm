#include<iostream>
using namespace std;

double cubic(double num) {
  double t = num;
  for (int i = 0;i<100;i++) {
    t = (2 * t * t * t + num) / (3 * t * t);
  }
  return t;
}

int main () {
  double n;
  scanf("%d", &n);
  printf("%.6lf", cubic(n));
}