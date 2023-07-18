#include <bits/stdc++.h>
#include <cmath>

#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<vector<ll>> graph;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, s, n) for (ll i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()

int main() {
  int n;
  cin >> n;
  graph G(n);
  rep(i, n) {
    int u, k;
    cin >> u >> k;
    u--;
    rep(j, k) {
      int v;
      cin >> v;
      v--;
      G[u].push_back(v);
    }
    reverse(all(G[u]));
  }
  vector<bool> seen(n, false);
  vector<int> d(n, -1), f(n, -1);
  int t = 1;
  rep(i, n) {
    if(seen[i]) continue;
    stack<int> S;
    S.push(i);
    while(!S.empty()){
      int u = S.top();
      // 未訪問ならば訪問済みにする
      if(d[u] == -1) d[u] = t++;
      // 訪問済みであることを更新
      seen[u] = true;

      // 頂点を追加したかのフラグ
      bool flag = false;
      for(auto v : G[u]){
        if(seen[v]) continue;
        S.push(v);
        flag = true;
      }
      // 頂点を追加しなかった場合は、スタックから取り出す
      if(!flag){
        S.pop();
        if(f[u] == -1) f[u] = t++;
      }
    }
  }

  rep(i, n) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
  }
  return 0;
}
