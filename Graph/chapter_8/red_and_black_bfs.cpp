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

int main() {
  while(true){
  int h, w;
  cin >> w >> h;
  if(h == 0 && w == 0) break;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  // 人の位置を探す
  int sx, sy;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '@') {
      sx = i;
      sy = j;
    }
  }

  // BFS
  int ans = 0;
  vector<int> dx = { 1, 0, -1, 0 }, dy = { 0, 1, 0, -1 };
  vector seen(h, vector<bool>(w, false));
  seen[sx][sy] = true;

  queue<P> que;
  que.push({ sx, sy });
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();
    ans++;
    rep(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (seen[nx][ny] || s[nx][ny] == '#') continue;
      seen[nx][ny] = true;
      que.push({ nx, ny });
    }
  }
  cout << ans << endl;
  }
  return 0;
}
