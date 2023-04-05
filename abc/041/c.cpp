#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector a(n, 0ll);
  rep(i, n) cin >> a[i];

  map<ll, ll> idx;
  rep(i, n) idx[a[i]] = i + 1;

  auto b = a;
  sort(b.rbegin(), b.rend());

  rep(i, n) cout << idx[b[i]] << '\n';
  return 0;
}