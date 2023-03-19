#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> b(m);
  rep(i, m) cin >> b[i];

  vector<ll> c;
  rep(i, n) c.emplace_back(a[i]);
  rep(i, m) c.emplace_back(b[i]);
  sort(c.begin(), c.end());

  map<ll, ll> pos;
  rep(i, n+m) pos[c[i]] = i + 1;

  rep(i, n) cout << pos[a[i]] << ' ';
  cout << '\n';
  rep(i, m) cout << pos[b[i]] << ' ';
  cout << '\n';
  return 0;
}