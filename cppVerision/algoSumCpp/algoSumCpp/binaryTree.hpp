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

/*vertical order*/
vector<vector<int>> verticalOrder(TreeNode * root) {
  vector<vector<int>> ans;
  if (root == nullptr) return ans;
  map<int, vector<int>> m;
  queue<pair<int, TreeNode*>> q;
  q.push({ 0,root });
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    m[cur.first].push_back(cur.second->val);
    if (cur.second->left != nullptr) q.push({ cur.first-1,cur.second->left });
    if (cur.second->right != nullptr) q.push({ cur.first + 1,cur.second->right });
  }
  for (auto a : m)ans.push_back(a.second);
  return ans;
}
/***************************************************************/

/*level order*/
void levelOrder(TreeNode*root) {
  queue<TreeNode*>q;
  TreeNode*last = root, *nextLast = root;
  int width = 0;
  if (root == nullptr) return;
  q.push(root);
  while (!q.empty()) {
    TreeNode*cur = q.front();
    q.pop();
    cout << cur->val;
    if (cur->left) q.push(cur->left);
    if (cur->right) q.push(cur->right);
    if(!q.empty()) nextLast = q.back();
    if (cur == last) {
      cout << endl;
      last = nextLast;
      width = max(width, (int)q.size());
    }
  }
  cout << "max width: " << width << endl;
}
