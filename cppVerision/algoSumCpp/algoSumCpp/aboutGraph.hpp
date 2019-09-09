#pragma once
#include "head.hpp"


//

//dijkstra
vector<int> shortestPathDijkstra(vector<vector<int>>& disMap, int source) {
  int n = disMap.size();
  vector<int> distance(n, INT_MAX);
  vector<bool> visited(n, 0);
  int start = source;
  visited[start] = 1;
  for (int i = 0;i < n;++i) {
    distance[i] = min(distance[i], disMap[start][i]);
  }
  for (int i = 0;i < n - 1;++i) {
    int minN = INT_MAX;
    for (int j = 0;j < n;++j) {
      if (visited[j] == 0 && distance[j] < minN) {
        minN = distance[j];
        start = j;
      }
    }
    visited[start] = 1;
    for (int j = 0;j < n;++j) {
      distance[j] = min(distance[j], distance[start] + disMap[start][j]);
    }
  }
  return distance;
}
//KM
//二分图的最优匹配
bool KMdfs(int n) {
  vector<int>a;
  return false;
}