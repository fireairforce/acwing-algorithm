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
    // 初始的时候做n次插入操作，这里就是个差分的思想
    // b此时就是a的差分数组
    // 这里把初始化的a数组值全都想成0,那么此时差分数组也全是0，这时候初始化之后成了a1...an
    // 那么差分数组则相当于插入n次 a1...an 这个值
    // 这里可以思考一波(反过来也可以想一想)
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