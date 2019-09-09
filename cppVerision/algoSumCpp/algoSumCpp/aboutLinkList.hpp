#pragma once
#include"head.hpp"
using namespace std;

struct ListNode {
  int val;
  ListNode * next;
  ListNode(int _val) :val(_val), next(NULL) {}
};

/************************************************/
//input ans output
ListNode* inputList() {
  int tmp;
  ListNode *helper = new ListNode(-1);
  ListNode *p = helper;
  while (cin >> tmp) {
    p->next = new ListNode(tmp);
    p = p->next;
  }
  return helper->next;
}

void outputList(ListNode *head) {
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

ListNode *dumpList(ListNode *head) {
  if (head == nullptr) return nullptr;
  ListNode *dump = new ListNode(head->val);
  dump->next = dumpList(head->next);
  return dump;
}
/*************************************************/

//reverse List
ListNode * reverseList(ListNode * head) {
  if (head == nullptr || head->next == nullptr) return head;
  ListNode *h = head, *p = head->next;
  h->next = nullptr;
  while (p->next != nullptr) {
    ListNode *t = p->next;
    p->next = h;
    h = p;
    p = t;
  }
  p->next = h;
  return p;
}

//insert a node at the pos, with a value of val
ListNode * insertList(ListNode *head, int pos, int val) {
  ListNode *p = head;
  int count = 0;
  while (count < pos-1) {
    p = p->next;
    ++count;
    if (p == nullptr) {
      throw new exception("error: List is not long enough!");
      return nullptr;
    }
  }
  ListNode *q = p->next;
  p->next = new ListNode(val);
  p->next->next = q;
  return head;
}

//delete a node at pos 
ListNode *deleteList(ListNode *head, int pos) {
  ListNode *p = head;
  int count = 0;
  while (count < pos - 1) {
    p = p->next;
    ++count;
    if (p == nullptr) {
      cout << "list has no such a position" << endl;
      return head;
    }
  }
  p->next = p->next->next;
  return head;
}

//kth node from the tail
int kthNodeFromTail(ListNode* head, int k) {
  ListNode *p = head, *pk = head;
  for (int i = 0;i < k;++i) {
    pk = pk->next;
  }
  while (pk != nullptr) {
    p = p->next;
    pk = pk->next;
  }
  return p->val;
}
//

void printListReversinglyRec(ListNode * head) {
  if (head != nullptr) {
    if (head->next != nullptr) {
      printListReversinglyRec(head->next);
    }
    cout << head->val << " ";
  }
}


//odd even sort, group all odd value nodes together followed by the even value nodes
ListNode *oddEvenSort(ListNode *head) {
  if (head == nullptr || head->next == nullptr) return head;
  ListNode *helper1 = new ListNode(-1);
  helper1->next = head;
  ListNode *helper2 = new ListNode(-1);
  ListNode *pre = helper1, *cur = head, *hp2 = helper2;
  while (cur != nullptr) {
    //cout << cur->val << endl;
    if (cur->val % 2 == 0) {
      pre->next = cur->next;
      hp2->next = cur;
      hp2 = hp2->next;
      cur->next = nullptr;
      cur = pre->next;
    }
    else {
      cur = cur->next;
      pre = pre->next;
    }
  }
  pre->next = helper2->next;
  return head;
}

//if the List is palindrome
bool isPalindrome(ListNode *head) {
  if (head == nullptr) return false;
  else if (head->next == nullptr)return true;
  ListNode*revHead = reverseList(dumpList(head));
  ListNode*p1 = head, *p2 = revHead;
  while (p1 != nullptr || p2 != nullptr) {
    if (p1->val != p2->val)return false;
    p1 = p1->next;
    p2 = p2->next;
  }
  if (p1 == nullptr && p2 == nullptr)return true;
  else return false;
}