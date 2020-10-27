# string
一般写cpp都会用这个库，写字符串的题目都会用string

最大的优势在于其可以创造一个动态的数组。

## 操作

```C++
string s1;
// 动态的复制
string s2 = s1;
// 不能用 scanf 读入string
// 能用printf输出 printf("%s\n", s1.c_str());
// string读入一行要用 getline(cin, s);

// 判断字符串是否为空
s1.empty();
s2.empty();

// 长度 O(1) 的时间复杂度，可以写在循环里面
s1.size();

// 判断string 大小和变量一样比较就可以了

// 字符串可以累加

// 处理string中的字符
for (char c: s) {
  cout << c << endl;
}

for (int i = 0;i<s.size();i++) {
  cout << s[i] << endl;
}

// 改变string里面的值
// 在变量前面加上一个引用符号
// 不加就相当于复制到一个新到变量里面去了
for (char &c: s) {
  c = 'x';
}

// 可以使用 auto 让编辑器去猜变量的类型
for (auto &c: s) {
  c = 'm';
}

// auto可以使用到一些复杂类型的推导省略简写
```
