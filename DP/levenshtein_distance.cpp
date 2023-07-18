#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)

int main() {
  string s, t;
  cin>>s>>t;
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
  rep(i,s.size()+1) dp[i][0] = i;
  rep(i,t.size()+1) dp[0][i] = i;
  rep(i,s.size()){
    rep(j,t.size()){
      if (s[i] == t[j]) dp[i + 1][j + 1] = min({ dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] });
      else dp[i + 1][j + 1] = min({ dp[i][j + 1] + 1, dp[i + 1][j] + 1, dp[i][j] + 1 });
    }
  }
  cout << dp[s.size()][t.size()] << endl;
}