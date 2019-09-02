#include "head.hpp"
#include "topK.hpp"
#include "sort.hpp"
#include "aboutString.hpp"
#include "aboutPath.hpp"
#include "aboutLinkList.hpp"
#include "binaryTree.hpp"
#include "classicProb.hpp"

using namespace std;

//increase the num until maximum that s can describe
bool increaseString(string& s) {
  bool overFlow = 0;
  int carry = 0;
  int len = s.size();
  for (int i = len - 1;i > -1;++i) {
    int nSum = s[i] - '0' + carry;
    if (i == len - 1) nSum++;
    if (nSum >= 10) {
      if (i == 0) {
        overFlow = true;
      }
      else {
        nSum -= 10;
        carry = 1;
        s[i] = '0' + nSum;
      }
    }
    else {
      s[i] = '0' + nSum;
    }
  }
  return overFlow;
}

int main() {
  //topkHeapSort topk;
  //topkQuickSort topk;
  //int k,tmp;
  //cin >> k;
  //vector<int>input;
  //while (cin >> tmp) input.emplace_back(tmp);
  //vector<int> ans = topk.getTopK(input, k);
  //for (int i = ans.size()-1;i>-1;--i) {
  //  cout << ans[i] << " " ;
  //}

  //sort
  //int tmp;
  //vector<int>input;
  //while (cin >> tmp) input.emplace_back(tmp);
  ////quickSort(input);
  ////heapSort(input);
  //mergeSort(input);
  //for (int i = 0;i<input.size();++i) {
  //    cout << input[i] << " " ;
  //  }

  //aboutString
  //string s = "wahaha hello world! how are you? fine thank you! and you?";
  //cin >> s;
  //reverseWords(s);
  //reverse(s.begin(), s.end());
  //cout << s << endl;
  //cout << longestUndupStr(s) << endl;
  //return 0;

  //List
  //int k;
  //cin >> k;
  //ListNode *head = inputList();
  //ListNode *ans = oddEvenSort(head);
  //ListNode *ans = reverseList(head);
  //ListNode *ans = insertList(head, 3, 8);
  //ListNode *ans = deleteList(head, 3);
  //cout << kthNodeFromTail(head, k) << endl;
  //outputList(ans);
  //printListReversinglyRec(head);

  /*test queue with list*/
  //QueueWithList ql = QueueWithList();
  //int n;
  //cin >> n;
  //for (int i = 0;i < n;++i) {
  //  int tmp;
  //  cin >> tmp;
  //  ql.push(tmp);
  //}
  //while (!ql.empty()) {
  //  cout << ql.front() << " ";
  //  ql.pop();
  //}
  //cout << endl;
  /*********************/
  /*int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0;i < n;++i) {
    for (int j = 0;j < m;++j) {
      cin >> matrix[i][j];
    }
  }
  cout << maxSumSubMat(matrix) << endl;*/
  //tree
  //TreeNode*root = new TreeNode(1);
  //root->left = new TreeNode(2);
  //root->right = new TreeNode(3);
  //root->left->left = new TreeNode(4);
  //root->left->right = new TreeNode(5);
  //root->right->right = new TreeNode(6);
  //root->right->left = new TreeNode(7);
  //root->right->left->right = new TreeNode(77);
  /*levelOrder(root);*/
  //vector<vector<int>> ans = verticalOrder(root);
  //for (auto a : ans) {
  //  for (auto i : a) cout << i << " ";
  //  cout << endl;
  //}
  string s;
  cin >> s;
  permutation(s);
  return 0;
}