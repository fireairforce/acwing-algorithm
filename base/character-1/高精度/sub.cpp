#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 判断大小
bool cmp(vector<int> &A, vector<int> &B) {
  if (A.size() != B.size()) {
    return A.size() > B.size();
  }
  for (int i = A.size() - 1; i >= 0;i --) {
    if (A[i] != B[i]) {
      return A[i] > B[i];
    }
  }
  return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
  if (A.size() < B.size()) {
    return sub(B, A);
  }
  vector<int>C;
  for (int i = 0;i<A.size();i++) {
    int t = A[i] - t;
    if (i < B.size()) {
      t-=B[i];
    }
    C.push_back((t + 10) % 10);
    if (t < 10) {

    }
  }
}

int main () {
  string a, b;
  vector<int>A;
  vector<int>B;
  cin >> a >> b;
  for (int i = a.size() - 1;i>=0;i--) {
    A.push_back(a[i]);
  }
  for (int i = b.size() - 1;i >= 0;i--) {
    B.push_back(b[i]);
  }
  if (cmp(A, B)) {
    auto C = sub(A, B);

    for (int i = C.size() - 1;i>=0;i--) {
      printf("%d", C[i]);
    }
  } else {
    auto C = sub(B, A);


  }
  return 0;
}