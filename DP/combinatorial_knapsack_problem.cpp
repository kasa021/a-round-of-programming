#include <bits/stdc++.h>
#include <cmath>

#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using graph = vector<vector<int>>;

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> v(n), w(n);
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  rep(i, n) cin >> v[i] >> w[i];
  rep(i,n){
    dp[i+1]= dp[i];
    rep(j,W+1){
      if(j-w[i]>=0){
        dp[i+1][j]=max(dp[i+1][j],dp[i][j-w[i]]+v[i]);
        dp[i+1][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
      }
    }
  }
  cout<<dp[n][W]<<endl;
}
//https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C