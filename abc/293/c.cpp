#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  vector<char> path;
  rep(i, h-1) path.emplace_back('d');
  rep(j, w-1) path.emplace_back('l');
  sort(path.begin(), path.end());

  ll ans = 0;
  do {
    ll i = 0; ll j = 0;
    set<ll> seen = {a[0][0]};
    bool ok = true;
    for (auto c : path) {
      if (c == 'd') ++i;
      if (c == 'l') ++j;
      if (seen.count(a[i][j])) {
        ok = false;
        break;
      }
      seen.emplace(a[i][j]);
    }

    if (ok) ++ans;
  } while (next_permutation(path.begin(), path.end()));

  cout << ans << '\n';
  return 0;
}