#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t;
// 判断大小
bool cmp(vector<int> &A, vector<int> &B)
{
  if (A.size() != B.size())
  {
    return A.size() > B.size();
  }
  for (int i = A.size() - 1; i >= 0; i--)
  {
    if (A[i] != B[i])
    {
      return A[i] > B[i];
    }
  }
  return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
  vector<int> C;
  for (int i = 0; i < A.size(); i++)
  {
    t = A[i] - t;
    if (i < B.size())
    {
      t -= B[i];
    }
    // 如果 t 是 >= 0 就是 t本身
    // <0 的话就相当于借位了
    C.push_back((t + 10) % 10);
    // 如果 t 比 0 小就要借位
    if (t < 0)
    {
      t = 1;
      // 否则不用处理
    }
    else
    {
      t = 0;
    }
  }
  // 处理一下前导 0 的情况
  while (C.size() > 1 && C.back() == 0)
    C.pop_back();

  return C;
}

int main()
{
  string a, b;
  vector<int> A;
  vector<int> B;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    A.push_back(a[i] - '0');
  }
  for (int i = b.size() - 1; i >= 0; i--)
  {
    B.push_back(b[i] - '0');
  }
  if (cmp(A, B))
  {
    auto C = sub(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
      printf("%d", C[i]);
    }
  }
  else
  {
    printf("-");
    auto C = sub(B, A);
    for (int i = C.size() - 1; i >= 0; i--)
    {
      printf("%d", C[i]);
    }
  }
  return 0;
}