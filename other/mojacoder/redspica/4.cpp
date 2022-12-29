#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/dsu>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  vector<ll> b(n);
  rep(i, n) cin >> b[i];

  vector<bool> red(n);
  rep(i, n) {
    char color;
    cin >> color;
    if (color == 'R') red[i] = true;
    else red[i] = false;
  }

  ll m;
  cin >> m;
  dsu uf(n);
  rep(_, m) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    uf.merge(x, y);
  }

  vector<ll> max_b(n);
  rep(i, n) {
    ll leader = uf.leader(i);
    auto chmax = [](auto& a, auto b) { if (a < b) a = b; };
    chmax(max_b[leader], b[i]);
  }

  ll ans = 0;
  rep(i, n) {
    ll leader = uf.leader(i);
    if (max_b[leader] == b[i] and red[i]) ++ans;
  }

  cout << ans << '\n';
  return 0;
}