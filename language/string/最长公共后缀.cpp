#include<iostream>
#include<string>
using namespace std;
int main () {
    int n;
    while (cin >> n, n) {
        string s[207];
        for (int i = 0;i<n;i++) {
            cin >> s[i];
        }
        int len = 999999;
        for (int j = 1;j<n;j++) {
          int count = 0;
          for (int i = 0;i<s[j].size() && i < s[i].size();i++) {
            if (s[j][s[j].size() - i - 1] != s[0][s[0].size() - i - 1]) {
              break;
            }
            count ++;
          }
          len = min(len, count);
        }
        string ansr;
        for (int i = s[0].size() - len;i < s[0].size();i ++) {
          ansr += s[0][i];
        }
        cout << ansr << endl;
    }
}