#include <bits/stdc++.h>
#include <cmath>

#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<vector<ll>> graph;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, s, n) for (ll i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()

vector<int> dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 };

int dfs(vector<string> &s, vector<vector<bool>> &seen, int x, int y, int &ans) {
  seen[x][y] = true;
  ans++;
  rep(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= s.size() || ny < 0 || ny >= s[0].size()) continue;
    if (seen[nx][ny] || s[nx][ny] == '#') continue;
    dfs(s, seen, nx, ny, ans);
  }
  return ans;
}

int main() {
  while(true){
    int w, h;
    cin >> w >> h;
    if(w == 0 && h == 0) break;
    vector<string> s(h);
    rep(i,h) cin>>s[i];

    // 人の位置を探す
    int sx, sy;
    rep(i,h) rep(j,w) {
      if (s[i][j] == '@') {
        sx = i;
        sy = j;
      }
    }

    // DFS
    int ans = 0;
    vector seen(h, vector<bool>(w, false));
    dfs(s, seen, sx, sy, ans);
    cout << ans << endl;
  }
}
