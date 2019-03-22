#include "head.hpp"
using namespace std;
//#define DEBUG
/*Manacher*/
/*longest palindrome sub-string*/
string manacher(string& s) {
  string tmp = "$#";
  for (int i = 0;i < s.size();++i) {
    tmp += s[i];
    tmp += "#";
  }
  vector<int>rad(tmp.size(), 0);
  int mx = 0, id = 0, resLen = 0, resCenter = 0;
  //id 当前延伸到最右的回文串中心，mx 相应的最右端坐标
  for (int i = 1;i < tmp.size();++i) {
    rad[i] = mx > i ? min(rad[2 * id - i], mx - i) : 1;
    while (tmp[i + rad[i]] == tmp[i - rad[i]]) ++rad[i];
    if (mx < i + rad[i]) {
      mx = i + rad[i];
      id = i;
    }
    if (resLen < rad[i]) {
      resCenter = i;
      resLen = rad[i];
    }
  }
  return s.substr((resCenter - resLen) / 2, resLen - 1);
}

/*longest common sub-string*/
int longestComSub(string s, string t) {
  int lens = s.size(), lent = t.size();
  if (lens == 0 || lent == 0) return 0;//one of strings is empty, the length of common sub-string is 0
  vector<vector<int>>table(2, vector<int>(lent, 0));
  int longest = 0;//longest length
  int start1 = -1, start2 = -1;
  int compare = 0;//times of comparisons
  for (int j = 0; j < lent; ++j){
    ++compare;
    if (s[0] == t[j]){
      table[0][j] = 1;
      if (longest == 0){
        longest = 1;
        start1 = 0;
        start2 = j;
      }
    }
  }
  for (int i = 1; i < lens; ++i){
    ++compare;
    // with odd/even to swith working row
    int cur = ((i & 1) == 1); //index for current working row
    int pre = ((i & 1) == 0); //index for previous working row
    table[cur][0] = 0;
    if (s[i] == t[0]){
      table[cur][0] = 1;
      if (longest == 0){
        longest = 1;
        start1 = i;
        start2 = 0;
      }
    }
    for (int j = 1; j < lent; ++j){
      ++compare;
      if (s[i] == t[j]){
        table[cur][j] = table[pre][j - 1] + 1;
        if (longest < table[cur][j]){
          longest = table[cur][j];
          start1 = i - longest + 1;
          start2 = j - longest + 1;
        }
      }
      else{
        table[cur][j] = 0;
      }
    }
  }
#ifdef DEBUG
  cout << "length = " << longest << endl;
  cout << "start from " << start1 << " of string 1 and from " << start2 << " of string 2" << endl;
#endif
  return longest;
}

/*find pattern in a string and locate it*/
int KMP(string s, string pattern) {
  vector<int> next(pattern.length(), -1);
  int k = -1;
  //calculate vector next
  for (int q = 1;q < pattern.length();++q) {
    while (k > -1 && pattern[k + 1] != pattern[q]) {
      k = next[k];
    }
    if (pattern[k + 1] ==pattern[q]) {
      k++;
    }
    next[q] = k;
  }
  //for (int p = 0;p < next.size();++p) {
  //  cout << next[p] << " ";
  //}
  //kmp
  int i = 0, j = 0;
  int lenS = s.size(), lenT = pattern.size();
  while (i < lenS && j < lenT) {
    if (j == -1 || s[i] == pattern[j]) {
      i++;
      j++;
    }
    else {
      j = next[j];
    }
  }
  return j == pattern.length() ? i - j : -1;
}