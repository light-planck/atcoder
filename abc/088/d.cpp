#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


ll di[4] = {0, 1, 0, -1};
ll dj[4] = {1, 0, -1, 0};


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  using P = pair<ll, ll>;
  P start = make_pair(0, 0);
  P goal = make_pair(h-1, w-1);

  deque<P> que;
  que.emplace_back(start);
  map<P, ll> dist;
  dist[start] = 1;
  bool ok = false;

  while (not que.empty()) {
    auto now = que.front();
    auto [i, j] = now; que.pop_front();

    if (s[i][j] == '#') continue;

    ll d = dist[now];
    if (now == goal) ok = true;

    rep(k, 4) {
      ll ni = i + di[k]; ll nj = j + dj[k];

      if (ni >= h or ni < 0) continue;
      if (nj >= w or nj < 0) continue;

      P next = make_pair(ni, nj);
      if (dist.count(next)) continue;

      que.emplace_back(next);
      dist[next] = d + 1;
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (s[i][j] == '.') ++ans;
  }
  ans -= dist[goal];

  if (ok) cout << ans << '\n';
  else cout << -1 << '\n';
  return 0;
}