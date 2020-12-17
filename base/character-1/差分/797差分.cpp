#include<iostream>

using namespace std;

const int N = 100000 + 7;
int a[N], b[N];

int main () {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    // 原数组里面的n个值记得是插入进去的
    for (int i = 1;i<=n;i++) {
        b[i] += a[i];
        b[i+1] -= a[i];
    }
    while(m--) {
     int l, r, x;
     cin >> l >> r >> x;
     b[l] += x;
     b[r + 1] -= x;
    }
    // 对差分数组求一遍前缀和
    for (int i =1;i<=n;i++) {
        b[i] += b[i-1]; 
    }
    for (int i = 1;i<=n;i++) {
        cout << b[i] << " ";
    }
    return 0;
}