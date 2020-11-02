#include<iostream>
using namespace std;

// 链表结构
// 一个val 一个next指针 
struct Node {
  int val;
  Node* next;
} *head;

int main () {
  for (int i = 1;i<=5;i++) {
    Node* p = new Node();
    p->val = i;
    p->next = head;
    head = p;
  }

  // 新加一个节点,一般通过这样的方式来添加节点
  Node *u = new Node();
  u->val = 10;
  u->next = head;
  head = u;

  // 链表的删除(遍历的时候遍历不到即可)，删除头节点之后的下一个节点
  head -> next = head -> next -> next;

  for (Node* p = head; p; p = p -> next) {
    cout << p -> val << ' ';
  }
  cout << endl;
  return 0;
}