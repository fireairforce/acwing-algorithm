# 常用的STL
这里的一些内容背下来就可以了。主要还是为了便于书写方便。

## vector

动态变长数组，支持随机访问，不支持在任意位置`o(1)`插入元素

声明
```cpp
#include<vector>

vector<int>a; // 长度动态变化的数组
vector<int>b[123];
// 结构体也可以存在vector中
structor rec {...};
vector<rec>c;
```

### size/empty
基本上大部分stl都包含这个用法

### clear
清空

### begin / end
begin 返回第一个迭代器。a如果是个非空的vector，那么 `*a.begin() = a[0];`

遍历 vector：
```cpp
for (int l = 0; l < a.size();l++) {
  cout << a[l] << endl;
}
for (vector<int>::iterator it = a.begin(); it != a.end();it++) cout << *it << endl;
```

### front/back
返回第一个/最后一个元素

### push_back(item) / pop_back() 
尾部插入一个元素/弹出最后一个元素

## queue
主要包括 queue 和 优先队列 priority_queue

声明:
```cpp
#include<queue>
struct rec {...}; queue<rec>q; // 结构体 rec 中必须定义小于号
priority_queue<int>q; // 大根堆
priority_queue<int, vector<int>, grater<int>>q;  // 小根堆
priority_queue<pair<int, int>>q;
```

### 循环队列 quque

- push 队尾插入
- pop 队头弹出
- front 返回队头元素
- back 返回队尾元素

### 优先队列

- push 元素入堆
- pop 删除堆顶元素
- top 查询堆顶元素

### stack
- push 栈顶加入元素
- pop 推出栈顶元素

### 双端队列 deque
在头部增删元素只需要 O(1) 的时间，与queue相比，deque 和数组一样支持随机访问

- begin/end 迭代器
- front/back 返回队首/队尾元素
- push_back / pop_back 从队尾添加元素，从队尾弹出元素
- push_front / pop_front 队首添加元素，队首弹出元素

### set 
包括 set 和 multiset 两个容器，前者有序，后者有序多重。
内部实现都是一颗红黑树。

声明:
```cpp
#include<set>

set<rec>s;
multiset<double>s;
```

### size/clear/empty

同上

### begin/end
begin 返回集合中元素最小值的迭代器，end返回最大。

### insert
`s.insert(x);` 把一个元素插入进 s 中，时间复杂度为 logn
如果set里面已经有了该元素，那就不会重复插入，对集合状态无影响。

### find
`s.find(x);`在集合中查找是否存在x，时间复杂度为 logn，不存在会返回 `s.end();`

### lower_bound / upper_bound

- 查找大于等于x的元素中的最小一个，并返回该元素的迭代器
- 查找大于x中的最小一个，并返回迭代器。

### earse 
- 删除的 it 可以是个迭代器 时间复杂度为 O(logn)
- 可以删除s中所有指为x的元素,时间复杂度为 O(k + logn),k是被删元素的个数

### count
s.count(x),返回s总等于s的元素的个数，时间复杂度也为 O(k + logn)

## map
map容器是一个键值对 key-value 的映射，内部实现了一颗以key为关键码的红黑树，map的 key/value 可以是任何类型。

声明:
```cpp
map<key_type, value_type>name;

map<long long, bool> vis;
map<string, int> hash;
map<pair<int, int>, vector<int>>test;
```

### insert/erase
与set一样，但要求插入的是 `pair<key_type, value_type>;`

### find
`h.find(x)`在map中查找key为x的二元组

### []操作符
`h[key]` 是返回 key 映射的 value 的引用，时间复杂度为 logn.
同时还可以通过赋值操作来改值。

