#include "head.hpp"
#include "aboutLinkList.hpp"
using namespace std;

//double stringCalculator(string s) {
//
//}

//����n����ӡһ����ȫ���������ڵ��Ŵ�1��n
//k��¼��ǰ�����ڵ�������ʣ��ڵ������һֵ�����ӡ�ò�ڵ㲢����һ�㣬�����ӡ��ʣ�����нڵ�����
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

//ջ���򣬸��������ջ����������
//�ȽϷ�ʽ��С���� �� ��С
bool comp(int a,int b,bool less) {
  if (less) return a <= b;
  else return a >= b;
}
//���帨��ջ�������������������շ����෴
//ԭʼջ��ջ������ʱ����ջΪ�ջ�ջ��Ԫ���뵱ǰԪ�ش�С����Ҫ��ֱ���븨��ջ
//���򵯳�����ջ�����·Ż�ԭʼջ��ֱ������������ѹ��
//���Ӹ���ջ���µ���ԭʼջ
void sortStack(stack<int>&s) {
  stack<int> t;//����ջ
  bool less = false;//����С��������false��Ϊ�Ӵ�С����ջ����ʼ
  //����ջ��ԭջ˳���෴
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

//����ʵ�ֶ���
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

//����Ӿ���
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

//�����������
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


//Nλ��ɾ��Kλʣ�µ���С
//ɾ����һ��������ҵ���
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