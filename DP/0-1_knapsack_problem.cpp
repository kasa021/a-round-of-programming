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
  int n, w;
  cin >> n >> w;
  vector<int> weight(n), value(n);
  rep(i, n) cin >> value[i] >> weight[i];
  // dp[i][j]: i番目までの品物から重さがjになるように選んだときの価値の総和の最大値
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
  rep(i, n) {
    rep(j, w + 1) {
      if (j < weight[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i]);
      }
    }
  }
  cout << dp[n][w] << endl;
}

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp