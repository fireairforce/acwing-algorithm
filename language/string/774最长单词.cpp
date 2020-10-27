#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main () {
    string s;
    getline(cin , s);
    int maxCount = -1;
    string res;
    for (int i = 0;i < s.size(); i++) {
        if (s[i] != ' ') {
            for (int j = i + 1;j < s.size();j++) {
                if (s[j] != ' ') {
                    continue;
                } else {
                    if (j - i > maxCount) {
                        maxCount = j - i;
                        res = s.substr(i, j);
                    }
                    i = j;
                    break;
                }
            }
        }
    }
    cout << res << endl;
}

// I am a student of Peking University.