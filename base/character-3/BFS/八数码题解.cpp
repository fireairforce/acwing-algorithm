#include<iostream>
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<queue>

using namespace std;

// 这题状态表示比较复杂
// 可以使用一个字符串来表示状态，把 3 * 3 的数组展成一行
// 怎么进行状态的转移也比较复杂(如何把一个状态变成其他状态)
// 可以先恢复成 3 * 3 数组，转移数字到空格上去，然后再恢复成字符串

int bfs (string start) {
  string end = "12345678x";
  queue<string> q;
  unordered_map<string, int> dist;

  q.push(start);
  dist[start] = 0;

  while (q.size()) {
    auto t = q.front();
    q.pop();
    int dx[4]= {-1,0,1,0}, dy[4] = {0, 1, 0, -1};

    int distance = dist[t];
    if (t == end) {
      return distance;
    }
    // 进行状态转移
    int k = t.find('x');
    int x = k / 3, y = k % 3;
    for (int i = 0; i < 4; i++) {
      int a = x + dx[i], b = y + dy[i];
      // x, y 是空格位置,a,b 
      if (a >= 0 && a < 3 && b >= 0 && b < 3) {
        // 下标对应到一维
        swap(t[k], t[a * 3 + b]);
        // 没有找到，就更新一下状态
        if (!dist.count(t)) {
          dist[t] = distance + 1;
          q.push(t);
        }
        swap(t[k], t[a * 3 + b]);
      }
    }
  }
  return -1;

}

int main () {
  char st[2];

  string start;
  for (int i = 0; i < 9; i ++) {
    char c;
    cin >> c;
    start += c;
  }
  cout << bfs(start) << endl;
  return 0;
}