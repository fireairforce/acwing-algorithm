#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
const int N = 100010;
int q[N];
int m;

int main () {
    cin >> m;
    int tt = -1, hh = 0;
    while (m --) {
        string str;
        int n;
        cin >> str;
        if (str == "query") {
            cout << q[hh] << endl;
        } else if (str == "push") {
            cin >> n;
            q[++tt] = n;
        } else if (str == "pop") {
            hh++;
        } else if (str == "empty") {
            if (hh > tt) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}