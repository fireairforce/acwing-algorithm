#include<iostream>
#include<cmath>

using namespace std;
const int N = 100007;
int a[N], b[N];

int main () {
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i<m;i++) {
        cin >> b[i];
    }
    int p, q;
    for (int i = 0,j = m - 1;i<m;i++) {
        while (a[i] + b[j] > x && j > 0) {
            j--;
        }
        if (j >= 0 && a[i] + b[j] == x) {
            p = i;
            q = j;
            break;
        }
    }
    cout << p << " " << q;
    return 0;
}