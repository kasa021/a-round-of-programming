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
  while (true) {
    string s;
    cin >> s;
    if (s == "0") break;
    int n = s.size();
    vector<vector<ll>> dp(11, vector<ll>(n + 1, 0));
    dp[s[0] - '0'][0] = 1;
    rep(i, n - 1) {
      rep(j, 11) {
        dp[(10 * j + (s[i + 1] - '0')) % 11][i + 1] += dp[j][i];
      }
      if (s[i + 1] != '0')
        dp[s[i + 1] - '0'][i + 1]++;
    }
    ll ans = 0;
    rep(i, n) ans += dp[0][i];
    cout << ans << endl;
  }
}