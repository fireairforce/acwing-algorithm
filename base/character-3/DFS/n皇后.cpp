#include<iostream>
#include<cstdio>
using namespace std;
// 注意这个 N 值不要开太小了，因为下面 bool 数组会使用
const int N = 20;

char g[N][N];

bool col[N], dg[N], udg[N];

int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0;i<n;i++) {
            puts(g[i]);
        }
        puts("");
        return;
    }
    // 枚举一下当前行可以用的列此时坐标 为 (u, i)
    for (int i = 0;i<n;i++) {
        // 判断当前坐标所在的斜线、反斜线上有没有使用过这个点
        // dg 表示正对角线、udg 是反对角线
        // 这里对角线的坐标通过截距来进行计算 b = y -x || b = y + x 因为偏移量不能是负，所以第一种 + n
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main () {
    cin >> n;
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n;j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}