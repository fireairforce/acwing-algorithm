#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 1e5 + 5;

int m;
int l[N], r[N], e[N], idx;

void init () {
  l[1] = 0, r[0] = 1;
  idx = 2;
}

void add (int k, int x) {
  e[idx] = x;
    l[idx] = k;
  r[idx] = r[k];

  l[r[k]] = idx;
  r[k] = idx;
  idx ++;
}

void removeNode(int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main () {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> m;
  init();
  int k, x;
  while (m --) {
    string str;
    cin >> str;
    if (str == "L") {
      cin >> x;
      add(0, x);
    } else if (str == "R") {
        
      cin >> x;
      add(l[1], x);
    } else if (str == "D") {
      cin >> k;
      // 因为idx 是从2开始的，因此真正的 k 为 k + 1
      removeNode(k + 1);
    } else if (str == "IL") {
      cin >> k >> x;
      add(l[k + 1], x);
    } else if (str == "IR") {
      cin >> k >> x;
      add(k + 1, x);
    }
  }
  for (int i = r[0]; i != 1; i = r[i]) {
    cout << e[i] << " ";
  }
  return 0;
}