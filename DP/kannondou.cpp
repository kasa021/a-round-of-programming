#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    rep(i, n) {
      if (i + 1 <= n) dp[i + 1] += dp[i];
      if (i + 2 <= n) dp[i + 2] += dp[i];
      if (i + 3 <= n) dp[i + 3] += dp[i];
    }
    int day = (dp[n] + 9) / 10;
    int year = (day + 364) / 365;
    cout << year << endl;
  }
}
// https://onlinejudge.u-aizu.ac.jp/problems/0168