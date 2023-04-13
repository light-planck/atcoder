#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll a, b;
  cin >> a >> b;
  --a; --b;

  ll h = 100; ll w = 100;
  vector<string> s(h, string(w, '.'));
  for (ll i = h/2; i < h; ++i) s[i] = string(w, '#');

  const vector<pair<ll, ll>> dij = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // 上半分の白をb個黒に塗る
  [&] {
    rep(i, h) rep(j, w) {
      if (b == 0) return;
      bool ok = true;

      for (auto [di, dj] : dij) {
        ll ni = i + di; ll nj = j + dj;
        if (ni < 0 or ni >= h) continue;
        if (nj < 0 or nj >= w) continue;
        if (s[ni][nj] == '#') ok = false;
      }

      if (ok){
        s[i][j] = '#';
        --b;
      }
    }
  } ();

  // 下半分の黒をa個分白に塗る
  [&] {
    for (ll i = h/2; i < h; ++i) rep(j, w) {
      if (a == 0) return;
      bool ok = true;

      for (auto [di, dj] : dij) {
        ll ni = i + di; ll nj = j + dj;
        if (ni < 0 or ni >= h) continue;
        if (nj < 0 or nj >= w) continue;
        if (s[ni][nj] == '.') ok = false;
      }

      if (ok) {
        s[i][j] = '.';
        --a;
      }
    }
  } ();

  cout << h << " " << w << '\n';
  for (string row : s) cout << row << '\n';
  return 0;
}