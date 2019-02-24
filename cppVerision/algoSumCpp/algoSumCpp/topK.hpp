#include "head.hpp"

using namespace std;

class topkHeapSort {
public:
  vector<int> getTopK (vector<int>& input, int K) {
    if (input.empty() || K == 0) return vector<int>();
    if (input.size() < K) return input;
    vector<int> ans(input.begin(), input.begin() + K);
    maxHeap(ans);
    for (int i = K;i < input.size();++i) {
      if (input[i] < ans[0]) {
        ans[0] = input[i];
        heapAdjust(ans, 0, K);
      }
    }
    return ans;
  }
private:
  void maxHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1;i > -1;--i) {
      heapAdjust(nums, i, len);
    }
  }
  void heapAdjust(vector<int>& nums, int st, int len) {
    int i = st, j = 2 * st + 1, key = nums[st];
    while (j < len) {
      if (j + 1 < len && nums[j + 1] > nums[j])j++;
      if (nums[j] < key) break;
      nums[i] = nums[j];
      i = j;
      j = 2 * i + 1;
    }
    nums[i] = key;
  }
};

class topkQuickSort {
public:
  vector<int> getTopK(vector<int>& input, int K) {

  }
private:
  void quickSelect(vector<int>& input, int left, int right, int K) {
  
  }
};