#include "head.hpp"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

/********************** pre order *******************************/
void preOrderRec(TreeNode *root) {
  if (root == nullptr) return;
  cout << root->val << " ";
  if (root->left != nullptr) preOrderRec(root->left);
  if (root->right != nullptr) preOrderRec(root->right);
}

void preOrder(TreeNode *root) {
  if (root == nullptr) return;
  stack<TreeNode*> s;
  TreeNode *p = root;
  while (p != nullptr || !s.empty()) {
    while (p != nullptr) {
      cout << p->val << " ";
      s.push(p);
      p = p->left;
    }
    if (!s.empty()) {
      p = s.top();
      s.pop();
      p = p->right;
    }
  }
}
/****************************************************************/

/*********************** in order *******************************/
void inorderRec(TreeNode *root) {
  if (root == nullptr) return;
  if (root->left != nullptr) inorderRec(root->left);
  cout << root->val << " ";
  if (root->right != nullptr) inorderRec(root->right);
}
void inorder(TreeNode *root) {
  if (root == nullptr) return;
  stack<TreeNode*> s;
  TreeNode *p = root;
  while (p != nullptr || !s.empty()) {
    while (p != nullptr) {
      s.push(p);
      p = p->left;
    }
    if (!s.empty()) {
      p = s.top();
      cout << p->val << " ";
      s.pop();
      p = p->right;
    }
  }
}
/****************************************************************/

/********************* post order *******************************/
void postorderRec(TreeNode *root) {
  if (root == nullptr) return;  
  if (root->left != nullptr) preOrderRec(root->left);
  if (root->right != nullptr) preOrderRec(root->right);
  cout << root->val << " ";
}

void postorder(TreeNode *root) {
  stack<TreeNode*> s;
  TreeNode *cur = nullptr;
  TreeNode *pre = nullptr;
  s.push(root);
  while (!s.empty()) {
    cur = s.top();
    if ((cur->left == nullptr&&cur->right == nullptr) || (pre != nullptr && (pre == cur->left || pre == cur->right))) {
      cout << cur->val << " ";
      s.pop();
      pre = cur;
    }
    else {
      if (cur->right != nullptr) s.push(cur->right);
      if (cur->left != nullptr) s.push(cur->left);
    }
  }
}
/****************************************************************/