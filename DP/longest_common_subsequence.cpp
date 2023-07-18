#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)

int main() {
  int cnt;
  cin >> cnt;
  while(cnt--){
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    rep(i,a.size()){
      rep(j,b.size()){
        if(a[i] == b[j]){
          dp[i+1][j+1] = max({dp[i][j] + 1, dp[i+1][j], dp[i][j+1]});
      }
        else{
          dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
      }
    }
    cout << dp[a.size()][b.size()] << endl;

    rep(i, a.size()+1){
      rep(j, b.size()+1){
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  }
}