#include "head.hpp"
#include "aboutLinkList.hpp"
using namespace std;

//double stringCalculator(string s) {
//
//}

//输入n，打印一个完全二叉树，节点编号从1到n
//k记录当前层最多节点数，若剩余节点大于这一值，则打印该层节点并换下一层，否则打印完剩余所有节点后结束
void printCompleteBT(int n) {
  int i = 1,k=1;
  while (i <= n) {
    if (n - i + 1 > k) {
      for(int j=0;j<k;++j) {
        cout << i<<" ";
        ++i;
      }
      cout << endl;
      k *= 2;
    }
    else {
      while (i <= n) {
        cout << i<<" ";
        ++i;
      }
      cout << endl;
      return;
    }
  }
}

//栈排序，给定无序的栈，进行排序
//比较方式，小到大 或 大到小
bool comp(int a,int b,bool less) {
  if (less) return a <= b;
  else return a >= b;
}
//定义辅助栈，其排序方向与所需最终方向相反
//原始栈出栈，若此时辅助栈为空或栈顶元素与当前元素大小符合要求，直接入辅助栈
//否则弹出辅助栈并重新放回原始栈，直到满足条件再压入
//最后从辅助栈重新倒入原始栈
void sortStack(stack<int>&s) {
  stack<int> t;//辅助栈
  bool less = false;//按从小到大排序，false则为从大到小，从栈顶开始
  //辅助栈与原栈顺序相反
  while (!s.empty()) {
    int cur = s.top();
    s.pop();
    if (t.empty() || comp(t.top(), cur, less)) t.push(cur);
    else {
      while (!t.empty() && !comp(t.top(), cur, less)) {
        int tmp = t.top();
        t.pop();
        s.push(tmp);
      }
      t.push(cur);
    }
  }
  while (!t.empty()) {
    s.push(t.top());
    t.pop();
  }
}

//链表实现队列
class QueueWithList {
public:
  QueueWithList(){
    frontN = nullptr;
    backN = nullptr;
  }

  int front() {
    if (frontN != nullptr) return frontN->val;
    else throw new exception("error, queue is empty");
  }
  int back() {
    if (backN != nullptr) return backN->val;
    else throw new exception("error, queue is empty");
  }
  void push(int val) {
    ListNode* newNode = new ListNode(val);
    if (backN != nullptr) {
      backN->next = newNode;
      backN = backN->next;
    }
    else {
      backN = newNode;
      frontN = newNode;
    }
  }
  void pop() {
    if (frontN != nullptr) {
      ListNode*tmp = frontN;
      frontN = frontN->next;
      delete tmp;
    }
    else throw new exception("error, queue is empty");
  }
  bool empty() {
    if (frontN == nullptr) return true;
    else return false;
  }
private:
  ListNode*helperN, *frontN, *backN;
};

//最大子矩阵
int maxSumSubMat(vector<vector<int>> & matrix) {
  int n = matrix.size();
  if (n == 0) return 0;
  int m = matrix[0].size();
  int maxSum = -1000000000;
  for (int i = 0;i < n;++i) {
    vector<int>colSum(m,0);
    for (int j = i;j < n;++j) {
      int sum = 0;
      for (int k = 0;k < m;++k) {
        colSum[k] += matrix[j][k];
        sum = max(sum, sum + colSum[k]);
        if (sum > maxSum) maxSum = sum;
      }
    }
  }
  return maxSum;
}

//最长递增子序列
int longestIncSubArray(vector<int> & nums) {
  int len = nums.size();
  vector<int>dp(len);
  dp[0] = 1;
  for (int i = 1;i < len;++i) {
    if (nums[i] >= nums[i - 1]) dp[i] = dp[i - 1] + 1;
    else dp[i] = 1;
  }
  int maxL=0, maxId=1;
  for (int i = 0;i < len;++i) {
    if (dp[i] > maxL) {
      maxL = dp[i];
      maxId = i;
    }
  }
  cout << "longest increase sub-array start from: " << maxId - maxL + 1 << ", end at: " << maxId << ", length is: " << maxL << endl;
  return maxL;
}


//N位数删除K位剩下的最小
//删除第一个左大于右的数
vector<int> deleteKmin(vector<int> & num, int k) {
  bool has = 0;
  while (k) {
    has = 0;
    for (int i = 0;i < num.size()-1;++i) {
      if (num[i] > num[i + 1]) {
        num.erase(num.begin() + i);
        has = 1;
      }
    }
    if (!has) {
      int id = -1,maxn=0;
      for (int i = 0;i < num.size();++i) {
        if (num[i] > maxn) {
          maxn = num[i];
          id = i;
        }
      }
      num.erase(num.begin() + id);
    }
    --k;
  }
  return num;
}

//ipv4与整数相互转化
unsigned int convertIPtoInt(const string ip) {
  vector<unsigned int> a(4);
  unsigned int ans = 0;
  int ids = 0, ide = 0,i=0;
  while (ids < ip.size()) {
    while (ide < ip.size() && ip[ide] != '.') ++ide;
    a[i]= stoi(ip.substr(ids, ide - ids));
    ids = ide + 1;
    ide = ide + 1;
    ++i;
  }
  ans = (a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3];
  return ans;
}
string convertInttoIP(unsigned int a) {
  string ans = "";
  unsigned int flag = 0xff000000,shift=24;
  for (int i = 0;i < 4;++i) {
    ans += to_string((a&flag) >> shift);
    ans += '.';
    flag = flag >> 8;
    shift -= 8;
  }
  ans.pop_back();
  return ans;
}

//best time to buy and sell stocks:
//1. 只允许买卖一次
int maxProfitBuySellOnce(vector<int> &prices) {
  if (prices.size() < 2) return 0;
  int buy = prices[0],maxPro=0;
  for (int i = 1;i < prices.size();++i) {
    if (prices[i] > buy) maxPro = max(maxPro, prices[i] - buy);
    else buy = prices[i];
  }
  return maxPro;
}
//2. 允许买卖多次
int maxProfitBuySellMultiTimes(vector<int> &prices) {
  if (prices.size() < 2) return 0;
  int total = 0;
  for (int i = 0;i < prices.size() - 1;++i) {
    if (prices[i + 1] - prices[i]) total += prices[i + 1] - prices[i];
  }
  return total;
}
//3. 最多买卖两次
int maxProfitBuySellTwiceMost(vector<int> &prices) {
  if (prices.size() < 2) return 0;
  int n = prices.size();
  vector<int> preProfit(n);
  vector<int> postProfit(n);
  int curMin = prices[0],curMax = prices[n-1];
  for (int i = 1;i < n - 1;++i) {
    curMin = min(curMin, prices[i]);
    preProfit[i] = max(preProfit[i - 1], prices[i] - curMin);
  }
  for (int i = n - 2;i >= 0;--i) {
    curMax = max(curMax, prices[i]);
    postProfit[i] = max(postProfit[i + 1], curMax - prices[i]);
  }
  int maxPro = 0;
  for (int i = 0;i < n;++i) {
    maxPro = max(maxPro, preProfit[i] + postProfit[i]);
  }
  return maxPro;
}
//4. 最多买卖k次
int maxProfitBuySellKMost(vector<int> &prices) {

}
//5. 交易后需要休息一天
int maxProfitBuySellWithCD(vector<int> &prices) {

}
//eight queens
