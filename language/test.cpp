#include<iostream>
using namespace std;
int strToInt(string str) {
        string s;
        for (int i = 0;str[i];i++) {
            if (str[i] <='9' && str[i] >= '0') {
                s += str[i];
            }
        }
        char prefix;
        for (int i = 0;str[i];i++) {
            if (str[i] != ' ') {
                prefix = str[i];
                break;
            }
        }
        int res = 0;
        int len = s.size();
        int k = 0;
        while (k < len) {
            res += (s[len - k -1] - '0') * pow(10, k); 
            k++;
        }
        if (prefix == '-') {
            res = -res;
            if (res < INT_MIN) {
              return INT_MIN;
            } else {
              return res;
            }
        } else {
            if (res > INT_MAX) {
                return INT_MAX;
            } else {
               return res;
            }
        }
    }
int main () {
  string s;
  cin >> s;
  cout << strToInt(s) << endl;
  return 0;
}