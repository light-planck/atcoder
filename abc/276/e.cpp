#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  auto id = [&](ll i, ll j) {
    return i*w + j;
  };

  ll n = h * w;
  dsu uf(n);

  rep(i, h) {
    rep(j, w-1) {
      if (s[i][j] == '.' and s[i][j+1] == '.') {
        uf.merge(id(i, j), id(i, j+1));
      }
    }
  }
  rep(j, w) {
    rep(i, h-1) {
      if (s[i][j] == '.' and s[i+1][j] == '.') {
        uf.merge(id(i, j), id(i+1, j));
      }
    }
  }

  const vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  vector<ll> points;
  rep(i, h) rep(j, w) {
    if (s[i][j] == 'S') {
      for (auto [di, dj] : dij) {
        ll ni = i+di; ll nj = j+dj;
        if (ni < 0 or ni >= h) continue;
        if (nj < 0 or nj >= w) continue;
        if (s[ni][nj] == '#') continue;

        points.emplace_back(id(ni, nj));
      }
    }
  }

  for (auto p : points) {
    for (auto q : points) {
      if (p == q) continue;

      if (uf.same(p, q)) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }

  cout << "No" << '\n';
  return 0;
}