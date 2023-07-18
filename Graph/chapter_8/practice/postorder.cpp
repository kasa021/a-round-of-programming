#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  // n: 頂点数, m: 辺の数
  int n, m;
  cin >> n>>m;
  vector<vector<int>> g(n);
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  rep(i, n) {
    sort(g[i].begin(), g[i].end(), greater<int>());
  }

  vector<int> postorder;
  vector<bool> visited(n, false);
  stack<int> st;
  st.push(0);

  while (!st.empty()) {
    int u = st.top();
    visited[u] = true;

    // 頂点を追加したかのフラグ
    bool flag = false;
    for (int v : g[u]) {
      if (!visited[v]) {
        st.push(v);
        flag = true;
      }
    }
    // 頂点を追加しなかった場合は、スタックから取り出す
    // 追加しなかった場合は、その頂点から行ける未訪問の頂点がないということ
    if (!flag) {
      st.pop();
      postorder.push_back(u);
    }
  }

  // 答えを出力
  for (int u : postorder) {
    cout << u << " ";
  }
  cout << endl;
  return 0;
}
