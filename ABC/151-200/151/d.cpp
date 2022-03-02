#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using ll = long long;


const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1,  0, -1};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  ll ans = 0;

  // スタートを全探索
  for (ll is = 0; is < h; ++is) {
    for (ll js = 0; js < w; ++js) {
      if (s[is][js] == '#') continue;

      vector<vector<ll>> dist(h, vector<ll>(w, -1));
      dist[is][js] = 0;

      deque<pair<ll, ll>> que;
      que.push_back(make_pair(is, js));

      auto update = [&](ll i, ll j, ll new_dist) {
        if (dist[i][j] != -1) return;

        dist[i][j] = new_dist;
        que.push_back(make_pair(i, j));
      };

      while (!que.empty()) {
        ll i = que.front().first;
        ll j = que.front().second;
        que.pop_front();

        rep(dir, 4) {
          ll i_next = i + dx[dir];
          ll j_next = j + dy[dir];

          if (i_next < 0 || i_next >= h || j_next < 0 || j_next >= w) continue;
          if (s[i_next][j_next] == '#') continue;

          update(i_next, j_next, dist[i][j] + 1);
        }
      }

      rep(i, h) rep(j, w) {
        if (dist[i][j] == -1) continue;

        chmax(ans, dist[i][j]);
      }
    }
  }

  cout << ans << "\n";
  return 0;
}