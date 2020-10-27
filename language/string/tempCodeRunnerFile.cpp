#include<iostream>
#include<string>
using namespace std;
int main () {
    int n;
    string s[207];
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        for (int i = 0;i<n;i++) {
            cin >> s[i];
        }
        string res;
        bool flag = true;
        for (int i = 0;i<s[0].size();i++) {
          for (int j = 1;j<sizeof(s);j++) {
            if (s[j][s[j].size() - i + 1] != s[0][s[0].size() - i + 1]) {
              flag = false;
              cout << res << endl;
              break;
            }
          }
          if (!flag) {
            break;
          }
          res += s[0][i];
        }
    }
    return 0;
}