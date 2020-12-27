#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 300010;
int n, m;
// a 数组是存的数字, s 是前缀和
int a[N], s[N];
vector<int>arr;

// 因为每次会有两组数，所以使用 pair 来存取
typedef pair<int, int>PII;
vector<PII> add, query;

int find (int x) {
  int l = 0, r = arr.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (arr[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return r + 1;
}

int main () {
  cin >> n >> m;
  while (n --) {
    int x, c;
    cin >> x >> c;
    add.push_back({x, c});
    arr.push_back(x);
  }
  while(m--) {
    int l ,r;
    cin >> l >> r;
    query.push_back({l, r});
    arr.push_back(l);
    arr.push_back(r);
  }
  // 去重
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  // 处理插入
  for (auto item: add) {
    int x = find(item.first);
    a[x] += item.second;
  }
  // 前缀和
  for (int i =1;i<n;i++) {
    s[i] = s[i-1] + a[i];
  }
  // 询问
  for (auto item: query) {
    int l = find(item.first), r= find(item.second);
    cout << s[r] - s[l-1] << endl;
  }
  return 0;
}
