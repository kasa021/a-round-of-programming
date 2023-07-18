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
  vector<int> dist(n, -1);
  rep(i,n){
    int u, k;
    cin >> u >> k;
    u--;
    rep(j,k){
      int v;
      cin >> v;
      v--;
      G[u].push_back(v);
    }
  }

  queue<int> que;
  que.push(0);
  dist[0] = 0;
  while(!que.empty()){
    int v = que.front();
    que.pop();
    for(auto nv : G[v]){
      if(dist[nv] != -1) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  rep(i,n){
    cout << i+1 << " " << dist[i] << endl;
  }
  return 0;
}
