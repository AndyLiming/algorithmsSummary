#include "head.hpp"
#include "topK.hpp"

using namespace std;

int main() {
  topkHeapSort topk;
  int k,tmp;
  cin >> k;
  vector<int>input;
  while (cin >> tmp) input.emplace_back(tmp);
  vector<int> ans = topk.getTopK(input, k);
  for (int i = ans.size()-1;i>-1;--i) {
    cout << ans[i] << " " ;
  }
}