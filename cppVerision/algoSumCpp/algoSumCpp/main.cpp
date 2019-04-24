#include "head.hpp"
#include "topK.hpp"
#include "sort.hpp"
#include "aboutString.hpp"
#include "aboutPath.hpp"
#include "aboutLinkList.hpp"
#include "binaryTree.hpp"

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
  ListNode *head = inputList();
  ListNode *ans = oddEvenSort(head);
  //ListNode *ans = reverseList(head);
  //ListNode *ans = insertList(head, 3, 8);
  //ListNode *ans = deleteList(head, 3);
  //cout << kthNodeFromTail(head, k) << endl;
  outputList(ans);
  //printListReversinglyRec(head);
  return 0;
}