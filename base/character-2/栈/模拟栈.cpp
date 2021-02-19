#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
const int N = 100010;
int stk[N];
int m;
int tt = 0;

int main () {
    cin >> m;
    while (m --) {
        string str;
        int n;
        cin >> str;
        if (str == "query") {
        } else if (str == "push") {
            cin >> n;
            stk[++tt] = n;
        } else if (str == "pop") {
            tt--;
        } else if (str == "empty") {
            if (tt > 0) {
              puts("NO");
            } else {
              puts("YES");
            }
        }
    }
    return 0;
}