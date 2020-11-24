#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
  vector<int> C;
  r = 0;
  for (int i = A.size() - 1; i >= 0;i--) {
    r = r * 10 + A[i];
    C.push_back(r / b);
    r %= b;
  }
  reverse(C.begin(), C.end());
  while(C.size() > 1 && C.back() == 0) {
    C.pop_back();
  }
  return C;
}

int main () {
  string a;
  int b;
  cin >> a >> b;
  vector<int>A;
  for (int i = a.size() - 1;i>=0;i--) {
    A.push_back(a[i] - '0');
  }
  // r 是余数，通过引用传递回来
  int r;
  auto C = div(A, b, r);
  for (int i = C.size() - 1;i>=0;i--) {
    cout << C[i];
  }
  cout << endl << r << endl;
  return 0;
}