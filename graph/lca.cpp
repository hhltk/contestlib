#include <algorithm>
#include <vector>
using namespace std;

#include "../datastruct/rmq.cpp"

// source: kactl
// O(n log n) preprocessing, O(1) queries
struct LCA {
  int T = 0;
  vector<int> time, dist;
  vector<pair<int, int>> r;
  RangeMinimumQuery<pair<int, int>> rmq;

  LCA(vector<vector<int>> &g)
      : time(g.size()), dist(g.size()), rmq((dfs(0, 0, g), r)) {}

  void dfs(int s, int e, vector<vector<int>> &g) {
    time[s] = int(r.size());
    r.push_back({dist[s], s});
    for (auto &u : g[s]) {
      if (u != e) {
        r.push_back({dist[s], s});
        dist[u] = dist[s] + 1;
        dfs(u, s, g);
      }
    }
  }
  int query(int a, int b) {
    auto [l, r] = minmax(time[a], time[b]);
    return rmq.getmin(l, r).second;
  }
};
