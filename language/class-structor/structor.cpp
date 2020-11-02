#include<iostream>
using namespace std;

// 链表结构
// 一个val 一个next指针 
struct Node {
  int val;
  Node* next;

  // 这个是结构体构造函数
  Node(int _val): val(_val), next(NULL) {}
};

int main () {
  // new 返回的是个地址，把地址分配给了p
  Node* p = new Node(1);
  auto q = new Node(2); // auto = Node*
  // 如果这里结构体变量是个指针就需要用 -> 来调用
  // 如果不是指针就用 . 来调用

  // 链表头节点一般指的是第一个节点的地址，而不是指的值
  p->next = q;

  Node *head = p;
  for (Node *i = head;i;i= i -> next) {
    cout << i -> val << endl;
  }
  return 0;
}