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
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  rep(i, m) cin >> c[i];

  vector<int> dp(n + 1, 1001001001);
  dp[0] = 0;
  rep(i, m) { // i番目のコイン
    rep(j, n + 1) { // j円
      if (j - c[i] >= 0) {
        dp[j] = min(dp[j], dp[j - c[i]] + 1);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}