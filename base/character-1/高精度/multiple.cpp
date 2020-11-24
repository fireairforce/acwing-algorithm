#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
// C = A * b ,A >= 0 && b > 0

vector<int> mul(vector<int> &A, int b) {
  vector<int> C;
  int t = 0;
  // 只要 t 不为 0 或者 A 还没有遍历完成就一直做下去
  for (int i = 0;i<A.size() || t; i ++) {
    // 如果A还没有枚举完，就t加上A[i]*b的一个结果
    if (i < A.size()) {
      t += A[i] * b;
    }
    // 只需要个位来作为结果
    C.push_back(t % 10);
    // 进位还是用 t /= 10
    t /= 10;
  }
  // 处理前导0
  while(C.size() > 1 && C.back() == 0) {
    C.pop_back();
  }
  return C;
}

int main () {
  string a;
  int b;
  cin >> a >> b;
  vector<int> A;
  for (int i = a.size() - 1;i>=0;i--) {
    A.push_back(a[i] - '0');
  }
  auto C = mul(A, b);
  for (int i = C.size() - 1;i>=0;i--) {
    cout << C[i];
  }
  return 0;
}