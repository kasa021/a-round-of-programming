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

void dfs(graph &G, int v, int &t, vector<bool> &seen, vector<int> &d, vector<int> &f){
  seen[v] = true;
  d[v] = t++;
  for(auto next_v : G[v]){
    if(seen[next_v]) continue;
    dfs(G, next_v, t, seen, d, f);
  }
  f[v] = t++;
}

int main() {
  int n;
  cin >> n;
  graph G(n);
  rep(i,n){
    int u, k;
    cin>>u>>k;
    u--;
    rep(j,k){
      int v;
      cin>>v;
      v--;
      G[u].push_back(v);
    }
  }
  vector<bool> seen(n, false);
  vector<int> d(n), f(n);
  int t = 1;

  rep(i,n){
    if(seen[i]) continue;
    dfs(G, i, t, seen, d, f);
  }

  rep(i,n){
    cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
  }
  return 0;
}
