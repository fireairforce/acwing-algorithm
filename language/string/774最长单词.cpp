#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main () {
    string s;
    getline(cin, s);
    int maxCount = -1;
    string res;
    int first = 0;
    int second = 0;
    for (int i =0;s[i];i++) {
        int j = i;
        while (s[j] != ' ' && s[j] != '.' && j < s.size()) {
            j ++;
        }
        if (maxCount < j - i + 1) {
            first = i;
            second = j;
            maxCount = j - i + 1;
        }
        i = j;
    }
    for (int i = first;i<=second && s[i] != '.';i++) {
        cout << s[i];
    }
    cout << endl;
}