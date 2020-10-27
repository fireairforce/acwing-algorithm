#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int main () {
  string s1;
  string s2 = s1;
  // 不能用 scanf 读入string
  // 能用printf输出 printf("%s\n", s1.c_str());
  // string读入一行要用 getline(cin, s);
  cin >> s1 >> s2;
  cout << s1 << " " << s2 << endl;
  return 0;
}