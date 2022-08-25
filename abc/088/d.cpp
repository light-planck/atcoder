#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
void print(vector<pair<ll, ll>>& vp) { for (auto [x, y] : vp) print(x, y); }


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector seen(h, vector<ll>(w));
  rep(i, h) rep(j, w) {
    if (s[i][j] == '#') seen[i][j] = -1;
  }

  using P = pair<ll, ll>;
  deque<P> que;
  P start = make_pair(0, 0);
  que.emplace_back(start);

  map<P, ll> dist;
  dist[start] = 0;

  ll di[4] = {0, 1, 0, -1};
  ll dj[4] = {1, 0, -1, 0};
  while (not que.empty()) {
    auto now = que.front();
    auto [i, j] = now; que.pop_front();
    ll d = dist[now];

    seen[i][j] = true;

    rep(k, 4) {
      if (i + di[k] >= h or i + di[k] < 0) continue;
      if (j + dj[k] >= w or j + dj[k] < 0) continue;

      P next = make_pair(i+di[k], j+dj[k]);
      if (dist.count(next)) continue;

      que.emplace_back(next);
      dist[next] = d + 1;
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (seen[i][j] == 0) ++ans;
  }

  cout << ans << '\n';
  return 0;
}