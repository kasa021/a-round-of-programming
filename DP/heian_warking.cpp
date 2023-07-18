#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, s, n) for (ll i = s; i < n; i++)
using ll = long long;
using P = pair<ll, ll>;
using twoP = pair<P, P>;

int main() {
  ll num;
  cin >> num;
  while (num--) {
    ll gx, gy, cnt;
    cin >> gx >> gy >> cnt;
    set<twoP> s;
    rep(i, cnt) {
      P v, u;
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      v = P(x1, y1);
      u = P(x2, y2);
      s.insert(twoP(min(v, u), max(v, u)));
    }
    vector<vector<ll>> dp(gx + 9, vector<ll>(gy + 9, 0));
    dp[0][0] = 1;
    rep(i, gx + 1) {
      rep(j, gy + 1) {
        if (i == 0 && j == 0) continue;
        if (!s.count(twoP(P(i - 1, j), P(i, j))) && i > 0) {
          dp[i][j] += dp[i - 1][j];
        }
        if (!s.count(twoP(P(i, j - 1), P(i, j))) && j > 0) {
          dp[i][j] += dp[i][j - 1];
        }
      }
    }
    if (dp[gx][gy] == 0) {
      cout << "Miserable Hokusai!" << endl;
    }
    else {
      cout << dp[gx][gy] << endl;
    }
  }
}

//https://onlinejudge.u-aizu.ac.jp/problems/2186
