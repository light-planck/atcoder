#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;


int main() {
  ll n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  rep(i, n) {
    if (s[i] > t[i]) swap(s[i], t[i]);
  }

  using mint = modint998244353;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  mint a = 0;
  mint base = 1;
  for (auto c : s) {
    ll d = c - '0';
    a += d*base;
    base *= 10;
  }

  mint b = 0;
  base = 1;
  for (auto c : t) {
    ll d = c - '0';
    b += d*base;
    base *= 10;
  }

  mint ans = a * b;
  cout << ans.val() << '\n';
  return 0;
}