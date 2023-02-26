#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

const vector<pair<ll, ll>> dij = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
  ll n;
  cin >> n;

  string s;
  cin >> s;

  ll i = 0; ll j = 0;
  set<pair<ll, ll>> seen;
  seen.emplace(i, j);
  bool ok = false;
  rep(k, n) {
    ll di = 0; ll dj = 0;
    if (s[k] == 'U') tie(di, dj) = dij[0];
    if (s[k] == 'D') tie(di, dj) = dij[1];
    if (s[k] == 'L') tie(di, dj) = dij[2];
    if (s[k] == 'R') tie(di, dj) = dij[3];
    i += di; j += dj;
    if (seen.count({i, j})) {
      ok = true;
      // cout << i << " " << j << '\n';
    }
    else seen.emplace(i, j);
  }

  if (ok) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}