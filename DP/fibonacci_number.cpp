#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  rep1(i, 2, n + 1) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n] << endl;
}
//https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_A