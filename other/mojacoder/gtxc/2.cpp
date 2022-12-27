#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w, n;
  cin >> h >> w >> n;

  map<pair<ll, ll>, pair<ll, ll>> sign;
  rep(_, n) {
    ll i, j; char d;
    cin >> i >> j >> d;
    --i; --j;

    if (d == 'U') sign[{i, j}] = {-1, 0};
    if (d == 'D') sign[{i, j}] = {1, 0};
    if (d == 'L') sign[{i, j}] = {0, -1};
    if (d == 'R') sign[{i, j}] = {0, 1};
  }

  set<pair<ll, ll>> visited;
  ll i = 0; ll j = 0;
  pair<ll, ll> dir = {1, 0};
  while (true) {
    visited.emplace(i, j);
    if (sign.count({i, j})) dir = sign[{i, j}];

    ll ni = i + dir.first; ll nj = j + dir.second;

    if (ni < 0 or ni >= h) break;
    if (nj < 0 or nj >= w) break;
    if (visited.count({ni, nj})) break;

    i = ni; j = nj;
  }

  ll q;
  cin >> q;

  while (q--) {
    ll a, b;
    cin >> a >> b;
    --a; --b;

    if (visited.count({a, b})) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}