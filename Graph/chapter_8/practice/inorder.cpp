#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Edge {
  int left;
  int right;
};

int main() {
  // n: 頂点数, m: 辺の数
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  rep(i, m) {
    // p: 親の頂点, l: 左の子の頂点, r: 右の子の頂点
    int p, l, r;
    cin >> p >> l >> r;
    g[p].push_back({ l, r });
    cout<<g[p][0].left<<" "<<g[p][0].right<<endl;
  }
  rep(i,n){
    if(g[i].size()==0)g[i].push_back({-1,-1});
  }

  vector<int> inorder;
  auto dfs = [&](auto self, int u) -> void {
    for (Edge e : g[u]) {
      // 左の子がいるなら左の子を訪問
      if (e.left != -1) self(self, e.left);
      inorder.push_back(u);
      // 右の子がいるなら右の子を訪問
      if (e.right != -1) self(self, e.right);
    }
  };


  dfs(dfs, 0);

  for (int u : inorder) {
    cout << u << " ";
  }
  cout << endl;
  return 0;
}
