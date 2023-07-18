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
  int n, t, l, b, cnt = 0;
  double ans = 0;
  while (true) {
    ans = 0;
    cin >> n >> t >> l >> b;
    if (n == 0 && t == 0 && l == 0 && b == 0) {
      break;
    }
    vector<bool> lose_turn(n + 9, false), back_turn(n + 9, false);
    rep(i, l) {
      int x;
      cin >> x;
      lose_turn[x] = true;
    }
    rep(i, b) {
      int x;
      cin >> x;
      back_turn[x] = true;
    }
    // dp[i][j] := iターン目にjマス進んでいる確率
    vector<vector<double>> dp(t + 9, vector<double>(n + 9, 0));
    dp[0][0] = 1;
    rep(i, t) {
      rep(j, n) {
        rep1(k, 1, 7) {
          int next = j + k;
          if (next > n) next = n - (next - n);
          if (lose_turn[next] && i + 2 <= t) dp[i + 2][next] += dp[i][j] / 6.0;
          else if (back_turn[next])
            dp[i + 1][0] += dp[i][j] / 6.0;
          else
            dp[i + 1][next] += dp[i][j] / 6.0;
        }
      }
    }
    rep(i, t + 1) {
      ans += dp[i][n];
    }
    printf("%.6f\n", ans);
  }
}