#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  // n: 頂点数, m: 辺の数
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(i, n) {
    sort(g[i].begin(), g[i].end(), greater<int>());
  }

  vector<int> preorder;
  vector<bool> visited(n, false);
  stack<int> st;
  st.push(0);

  while (!st.empty()) {
    int u = st.top();
    st.pop();
    visited[u] = true;
    // 初めて訪れたときに追加
    preorder.push_back(u);
    for (int v : g[u]) {
      if (!visited[v]) {
        st.push(v);
      }
    }
  }

  // 答えを出力
  for (int u : preorder) {
    cout << u << " ";
  }
  cout << endl;
  return 0;
}
