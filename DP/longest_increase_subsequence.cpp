#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)

int main() {
  int n,len=0;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  // dp[i]: 最後の要素がa[i]であるような最長増加部分列の長さ
  // l[i]: 長さがiであるような最長増加部分列における最終要素の最小値
  vector<int> dp(n+9, 0),l(n+9,0);
  dp[0] = 1;
  l[dp[0]] = a[0];
  len = 1;
  rep1(i, 1, n) {
    // 二分探索して、a[i]を最終要素とするような最長増加部分列の長さを求める
    int idx = lower_bound(l.begin()+1,l.begin()+len+1,a[i]) - l.begin();
    dp[i] = idx;  // この時点での最長増加部分列の長さ
    l[dp[i]] = a[i];  // この時点での最長増加部分列における最終要素の最小値
    len = max(len,dp[i]);  // 最長増加部分列の長さの最大値
  }
  cout << len << endl;
}